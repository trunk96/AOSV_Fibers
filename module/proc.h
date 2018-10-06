#include "fibers.h"
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/kallsyms.h>
#include <linux/slab.h>
#include <linux/stddef.h>
#include <linux/sched/task.h>
#include <linux/types.h>



#define PROC_STAT_LEN 512


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


typedef int (*proc_pident_readdir_t)(struct file *file, struct dir_context *ctx, const struct pid_entry *ents, unsigned int nents);

extern proc_pident_readdir_t readdir;

typedef struct dentry * (*proc_pident_lookup_t)(struct inode *dir, struct dentry *dentry, const struct pid_entry *ents, unsigned int nents);

extern proc_pident_lookup_t look;
