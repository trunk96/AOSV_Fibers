#include "proc.h"


int proc_fiber_base_readdir(struct file *file, struct dir_context *ctx){

								//create the array containing all the fibers that are in the selected node
								struct process * p;
								struct task_struct *task = get_pid_task(proc_pid(file_inode(file)), PIDTYPE_PID);
								unsigned long nents;
								int i, counter = 0;
								struct fiber *fp;

								p = find_process_by_tgid(task->tgid);

								if (p == NULL)
																return 0;

								nents = atomic64_read(&(p->last_fiber_id));
								struct pid_entry fiber_base_stuff[nents];
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
								return readdir(file, ctx, fiber_base_stuff, nents);
}


struct dentry *proc_fiber_base_lookup(struct inode *dir, struct dentry *dentry, unsigned int flags)
{
								//create the array containing all the fibers that are in the selected node
								struct process * p;
								struct task_struct *task = get_pid_task(proc_pid(dir), PIDTYPE_PID);
								unsigned long nents;
								int i, counter = 0;
								struct fiber *fp;

								p = find_process_by_tgid(task->tgid);


								if (p == NULL)
																return 0;

								nents = atomic64_read(&(p->last_fiber_id));
								struct pid_entry fiber_base_stuff[nents];
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

								//here we have the array, so we can call again readdir to show them into /proc/{PID}/fibers
								return look(dir, dentry, fiber_base_stuff, nents);
}




ssize_t proc_fiber_read(struct file *filp, char __user *buf, size_t len, loff_t *off){
								//build the string
								char string_abc[PROC_STAT_LEN] = "";
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

								snprintf(string_abc, PROC_STAT_LEN, "Currently Ongoing: %s\nStart Address: %lu\nCreator thread: %d\n# of current activations: %lu\n# of failed activations: %lu\nTotal execution time in user space: %lu\n",
																	(fp->attached_thread == NULL) ? "no" : "yes", (unsigned long)fp->start_address, fp->creator_thread, fp->activation_counter, atomic64_read(&(fp->failed_activation_counter)), fp->total_time/1000000000);


								if (*off >= strnlen(string_abc, PROC_STAT_LEN))
																return 0;
								i = min_t(size_t, len, strnlen(string_abc, PROC_STAT_LEN));
								if (copy_to_user(buf, string_abc, i)) {
																return -EFAULT;
								}
								*off += i;
								return i;

}
