#include "proc.h"
#include <linux/version.h>


int proc_fiber_base_readdir(struct file *file, struct dir_context *ctx){

				//create the array containing all the fibers that are in the selected node
				struct process * p;
				struct task_struct *task = get_pid_task(proc_pid(file_inode(file)), PIDTYPE_PID);
				unsigned long nents;
				struct pid_entry *fiber_base_stuff;
				int i, ret, counter = 0;
				struct fiber *fp;

				if(task == NULL || file == NULL || ctx == NULL)
								return -ENOENT;


				p = find_process_by_tgid(task->tgid);

				if (p == NULL)
								return 0;

				nents = atomic64_read(&(p->last_fiber_id));
				fiber_base_stuff = kmalloc(nents * sizeof(struct pid_entry), GFP_KERNEL);
				memset(fiber_base_stuff, 0, nents * sizeof(struct pid_entry));
				hash_for_each_rcu(p->fibers, i, fp, node){
								if (fp == NULL)
																break; //we should never be here
								fiber_base_stuff[counter].name = fp->name;
								fiber_base_stuff[counter].len = strlen(fp->name);
								fiber_base_stuff[counter].mode = (S_IFREG|(S_IRUGO));
								fiber_base_stuff[counter].iop = NULL;
								fiber_base_stuff[counter].fop = &f_fops;
								counter++;
				}

				//here we have the array, so we can call again readdir to show them into /proc/{PID}/fibers
				ret = readdir(file, ctx, fiber_base_stuff, nents);
				kfree(fiber_base_stuff);
				return ret;
}


struct dentry *proc_fiber_base_lookup(struct inode *dir, struct dentry *dentry, unsigned int flags)
{
				//create the array containing all the fibers that are in the selected node
				struct process * p;
				struct task_struct *task = get_pid_task(proc_pid(dir), PIDTYPE_PID);
				unsigned long nents;
				struct pid_entry *fiber_base_stuff;
				int i, counter = 0;
				struct fiber *fp;
				struct dentry *ret;

				if(task == NULL || dir == NULL || dentry == NULL)
								return ERR_PTR(-ENOENT);

				p = find_process_by_tgid(task->tgid);


				if (p == NULL)
								return 0;

				nents = atomic64_read(&(p->last_fiber_id));
				fiber_base_stuff = kmalloc(nents * sizeof(struct pid_entry), GFP_KERNEL);
				memset(fiber_base_stuff, 0, nents * sizeof(struct pid_entry));
				hash_for_each_rcu(p->fibers, i, fp, node){
								if (fp == NULL)
																break;   //we should never be here
								fiber_base_stuff[counter].name = fp->name;
								fiber_base_stuff[counter].len = strlen(fp->name);
								fiber_base_stuff[counter].mode = (S_IFREG|(S_IRUGO));
								fiber_base_stuff[counter].iop = NULL;
								fiber_base_stuff[counter].fop = &f_fops;
								counter++;
				}

				//here we have the array, so we can call again lookup to show them into /proc/{PID}/fibers
				ret = look(dir, dentry, fiber_base_stuff, nents);
				kfree(fiber_base_stuff);
				return ret;
}




ssize_t proc_fiber_read(struct file *filp, char __user *buf, size_t len, loff_t *off){
				//build the string
				char proc_stat_string[PROC_STAT_LEN] = "";
				struct process *ep;
				struct fiber *fp;
				size_t i;
				unsigned long fiber_id;

				struct task_struct *task = get_pid_task(proc_pid(file_inode(filp)), PIDTYPE_PID);

				ep = find_process_by_tgid(task->tgid);

				if (ep == NULL)
								return 0;


				kstrtoul(filp->f_path.dentry->d_name.name, 10, &fiber_id);
				fp = find_fiber_by_id(fiber_id, ep);

				if (fp == NULL)
								return 0;


				#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,18,0)

				snprintf(proc_stat_string, PROC_STAT_LEN, "Currently Ongoing: %s\nStart Address: 0x%016lx\nCreator thread: %d\n# of current activations: %lu\n# of failed activations: %lld\nTotal execution time in user space: %lu\n",
								(fp->attached_thread == NULL) ? "no" : "yes", (unsigned long)fp->start_address, fp->creator_thread, fp->activation_counter, atomic64_read(&(fp->failed_activation_counter)), fp->total_time/1000000000);
				#else

				snprintf(proc_stat_string, PROC_STAT_LEN, "Currently Ongoing: %s\nStart Address: 0x%016lx\nCreator thread: %d\n# of current activations: %lu\n# of failed activations: %ld\nTotal execution time in user space: %lu\n",
								(fp->attached_thread == NULL) ? "no" : "yes", (unsigned long)fp->start_address, fp->creator_thread, fp->activation_counter, atomic64_read(&(fp->failed_activation_counter)), fp->total_time/1000000000);

				#endif

				if (*off >= strnlen(proc_stat_string, PROC_STAT_LEN))
								return 0;
				i = min_t(size_t, len, strnlen(proc_stat_string, PROC_STAT_LEN));
				if (copy_to_user(buf, proc_stat_string, i)) {
							return -EFAULT;
				}
				*off += i;
				return i;
}
