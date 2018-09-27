#include "fibers.h"
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/kallsyms.h>

//extern struct hlist_head processes[2<<10];
extern struct process * find_process_by_tgid(pid_t);
extern struct fiber * find_fiber_by_id(pid_t, struct process *);

union proc_op {
								int (*proc_get_link)(struct dentry *, struct path *);
								int (*proc_show)(struct seq_file *m, struct pid_namespace *ns, struct pid *pid, struct task_struct *task);
};

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

int proc_fiber_base_readdir(struct file *file, struct dir_context *ctx)
{
								struct process *p = get_proc_process_fiber(file_inode(file));
								proc_readdir_de_t proc_readdir_de;
								int ret = -1;

								if (p != NULL) {
																proc_readdir_de = (proc_readdir_de_t) kallsyms_lookup_name("proc_readdir_de");
																ret = proc_readdir_de(file, ctx, p->proc_fiber);
								}
								return ret;
}


struct dentry *proc_fiber_base_lookup(struct inode *dir, struct dentry *dentry, unsigned int flags)
{
								struct dentry *de;
								struct process *p;
								proc_lookup_de_t proc_lookup_de;

								de = ERR_PTR(-ENOENT);
								p = get_proc_process_fiber(dir);
								if (p != NULL) {
																proc_lookup_de = (proc_lookup_de_t) kallsyms_lookup_name("proc_lookup_de");
																de = proc_lookup_de(dir, dentry, p->proc_fiber);
								}
								return de;
}

int proc_fiber_init(struct process *p)
{

								/*struct proc_dir_entry *fiber;
								   int err;

								   err = -ENOMEM;

								   //fiber = kmem_cache_zalloc(proc_dir_entry_cache, GFP_KERNEL);
								   fiber = kzalloc(sizeof(struct proc_dir_entry), GFP_KERNEL);
								   if (!fiber)
								        goto out;

								   fiber->subdir = RB_ROOT;
								   fiber->data = p;
								   fiber->nlink = 1;
								   fiber->namelen = 6;
								   fiber->parent = (struct proc_dir_entry *) kallsyms_lookup_name("proc_root");
								   fiber->name = fiber->inline_name;
								   memcpy(fiber->name, "fibers", 7);

								   err = -EEXIST;

								   p->proc_fiber = fiber;
								   return 0;
								   out:
								   return err;*/
								struct proc_dir_entry *proc_root = (struct proc_dir_entry *) kallsyms_lookup_name("proc_root");
								__proc_create_t __proc_create = (__proc_create_t) kallsyms_lookup_name("__proc_create");
								p->proc_fiber = __proc_create(&proc_root, "fibers", S_IFDIR, 2);
								return 0;
}

void proc_fiber_exit(struct process *p)
{
								/*if (S_ISLNK(p->proc_fiber->mode))
								        kfree(p->proc_fiber->data);
								   if (p->proc_fiber->name != p->proc_fiber->inline_name)
								        kfree(p->proc_fiber->name);
								   kfree(p->proc_fiber);*/
								proc_remove(p->proc_fiber);
}



ssize_t proc_fiber_read(struct file *filp, char __user *buf, size_t len, loff_t *off){
								//build the string
								char string_abc[512] = "";
								struct proc_info *pinfo;
								struct process *ep;
								struct fiber *fp;
								size_t i;
								void * data = (PDE_DATA(file_inode(filp)));

								if (data == NULL)
																return 0;

								pinfo = (struct proc_info*) data;

								//printk(KERN_DEBUG "%s: proc received PID %d and FID %d\n", KBUILD_MODNAME, pinfo->process_id, pinfo->fiber_id);

								ep = find_process_by_tgid(pinfo->process_id);

								if (ep == NULL)
																return 0;

								fp = find_fiber_by_id(pinfo->fiber_id, ep);

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
