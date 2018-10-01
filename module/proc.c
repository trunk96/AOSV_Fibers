#include "fibers.h"
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/kallsyms.h>
#include <linux/slab.h>
#include <linux/stddef.h>
#include <linux/sched/task.h>
#include <linux/types.h>




//extern struct hlist_head processes[2<<10];
extern struct process * find_process_by_tgid(pid_t);
extern struct fiber * find_fiber_by_id(pid_t, struct process *);



typedef int (*proc_setattr_t)(struct dentry *dentry, struct iattr *attr);
extern proc_setattr_t setattr;





struct proc_inode {
								struct pid *pid;
								unsigned int fd;
								union proc_op op;
								struct proc_dir_entry *pde;
								struct ctl_table_header *sysctl;
								struct ctl_table *sysctl_entry;
								struct hlist_node sysctl_inodes;
								const struct proc_ns_operations *ns_ops;
								struct inode vfs_inode;
};



ssize_t proc_fiber_read(struct file *, char __user *, size_t, loff_t *);
int proc_fiber_init(struct process *);
void proc_fiber_exit(struct process *);
int proc_fiber_base_readdir(struct file *, struct dir_context *);
struct dentry *proc_fiber_base_lookup(struct inode *, struct dentry *, unsigned int);

static inline struct proc_inode *PROC_I(const struct inode *inode)
{
								return container_of(inode, struct proc_inode, vfs_inode);
}

static inline struct pid *proc_pid(struct inode *inode)
{
								return PROC_I(inode)->pid;
}



typedef int (*proc_readdir_de_t)(struct file *, struct dir_context *, struct proc_dir_entry *);
typedef struct proc_dir_entry *(*__proc_create_t)(struct proc_dir_entry **, const char *, umode_t, nlink_t);
typedef struct dentry *(*proc_lookup_de_t)(struct inode *, struct dentry *, struct proc_dir_entry *);

struct process * get_proc_process_fiber(struct inode *dir){
								struct task_struct *task;
								struct process *p = NULL;

								rcu_read_lock();
								task = pid_task(proc_pid(dir), PIDTYPE_PID);
								if (task != NULL) {
																p = find_process_by_tgid(task->tgid);
								}
								rcu_read_unlock();
								return p;
}


struct file_operations f_fops = {
								read: proc_fiber_read,
};


/*int proc_fiber_base_readdir(struct file *file, struct dir_context *ctx)
   {

        struct process *p = get_proc_process_fiber(file_inode(file));
        struct task_struct *task = get_pid_task(proc_pid(file_inode(file)), PIDTYPE_PID);

        if (p == NULL)
                return -ENOENT;

        if (!dir_emit_dots(file, ctx))
                goto out;
        if (ctx->pos >= 2 + atomic64_read(&(p->last_fiber_id)))
                goto out;

        struct fiber * fp;
        char name[256] = "";
        proc_fill_cache_t proc_fill_cache = (proc_fill_cache_t) kallsyms_lookup_name("proc_fill_cache");
        int i;
        hash_for_each_rcu(p->fibers, i, fp, node){
                snprintf(name, 256, "%d", fp->fiber_id);
                if (!proc_fill_cache(file, ctx, name, strlen(name), proc_fiber_instantiate, task, fp))
                        break;
                ctx->pos++;
        }
   out:
        put_task_struct(task);
        return 0;

   }*/

typedef int (*proc_pident_readdir_t)(struct file *file, struct dir_context *ctx, const struct pid_entry *ents, unsigned int nents);

extern proc_pident_readdir_t readdir;

typedef struct dentry * (*proc_pident_lookup_t)(struct inode *dir, struct dentry *dentry, const struct pid_entry *ents, unsigned int nents);

extern proc_pident_lookup_t look;


int proc_fiber_base_readdir(struct file *file, struct dir_context *ctx){
								//create the array containing all the fibers that are in the selected node
								struct process * p;
								struct task_struct *task = get_pid_task(proc_pid(file_inode(file)), PIDTYPE_PID);


								//printk(KERN_DEBUG "%s: proc received PID %d and FID %d\n", KBUILD_MODNAME, pinfo->process_id, pinfo->fiber_id);



								p = find_process_by_tgid(task->tgid);

								if (p == NULL)
																return 0;

								unsigned long nents = atomic64_read(&(p->last_fiber_id));
								printk(KERN_DEBUG "%s: proc received PID %d\n", KBUILD_MODNAME, p->process_id);
								struct pid_entry fiber_base_stuff[nents];
								memset(fiber_base_stuff, 0, nents * sizeof(struct pid_entry));
								int i, counter = 0;
								struct fiber *fp;
								hash_for_each_rcu(p->fibers, i, fp, node){
																if (fp == NULL)
																								break; //we should never be here
																//fiber_base_stuff[counter] = REG(fp->name, S_IRUGO, f_fops);
																fiber_base_stuff[counter].name = fp->name;
																fiber_base_stuff[counter].len = sizeof(fp->name) - 1;
																fiber_base_stuff[counter].mode = (S_IFREG|(S_IRUGO));
																fiber_base_stuff[counter].iop = NULL;
																fiber_base_stuff[counter].fop = &f_fops;
																counter++;
								}

								//here we have the array, so we can call again readdir to show them into /proc/{PID}/fibers
								return readdir(file, ctx, fiber_base_stuff, nents);
								//return 0;
}






struct dentry *proc_fiber_base_lookup(struct inode *dir, struct dentry *dentry, unsigned int flags)
{
								/*struct dentry *de;
								   struct process *p;
								   proc_lookup_de_t proc_lookup_de;

								   de = ERR_PTR(-ENOENT);
								   p = get_proc_process_fiber(dir);
								   if (p != NULL) {
								        proc_lookup_de = (proc_lookup_de_t) kallsyms_lookup_name("proc_lookup_de");
								        de = proc_lookup_de(dir, dentry, p->proc_fiber);
								   }
								   return de;*/

								//create the array containing all the fibers that are in the selected node
								struct process * p;
								struct task_struct *task = get_pid_task(proc_pid(dir), PIDTYPE_PID);


								//printk(KERN_DEBUG "%s: proc received PID %d and FID %d\n", KBUILD_MODNAME, pinfo->process_id, pinfo->fiber_id);

								p = find_process_by_tgid(task->tgid);

								if (p == NULL)
																return 0;

								unsigned long nents = atomic64_read(&(p->last_fiber_id));
								struct pid_entry fiber_base_stuff[nents];
								memset(fiber_base_stuff, 0, nents * sizeof(struct pid_entry));
								int i, counter = 0;
								struct fiber *fp;
								hash_for_each_rcu(p->fibers, i, fp, node){
																if (fp == NULL)
																								break;   //we should never be here
																//fiber_base_stuff[counter] = REG(fp->name, S_IRUGO, f_fops);
																fiber_base_stuff[counter].name = fp->name;
																fiber_base_stuff[counter].len = sizeof(fp->name) - 1;
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
								char string_abc[512] = "";
								struct proc_info *pinfo;
								struct process *ep;
								struct fiber *fp;
								size_t i;
								/*void * data = (PDE_DATA(file_inode(filp)));

								   if (data == NULL)
								        return 0;

								   pinfo = (struct proc_info*) data;*/
								struct task_struct *task = get_pid_task(proc_pid(file_inode(filp)), PIDTYPE_PID);


								//printk(KERN_DEBUG "%s: proc received PID %d and FID %d\n", KBUILD_MODNAME, pinfo->process_id, pinfo->fiber_id);

								ep = find_process_by_tgid(task->tgid);

								if (ep == NULL)
																return 0;

								unsigned long fiber_id;
								kstrtoul(filp->f_path.dentry->d_name.name, 10, &fiber_id);
								fp = find_fiber_by_id(fiber_id, ep);

								if (fp == NULL)
																return 0;

								snprintf(string_abc, 4096, "Currently Ongoing: %s\nStart Address: %lu\nCreator thread: %d\n# of current activations: %lu\n# of failed activations: %lu\nTotal execution time in user space: %lu\n",
																	(fp->attached_thread == NULL) ? "no" : "yes", (unsigned long)fp->start_address, fp->creator_thread, fp->activation_counter, atomic64_read(&(fp->failed_activation_counter)), fp->total_time/1000000000);

								//printk(KERN_DEBUG "%s: %s\n", KBUILD_MODNAME, string_abc);

								if (*off >= strnlen(string_abc, 4096))
																return 0;
								i = min_t(size_t, len, strnlen(string_abc, 4096));
								if (copy_to_user(buf, string_abc, i)) {
																return -EFAULT;
								}
								*off += i;
								return i;

}
