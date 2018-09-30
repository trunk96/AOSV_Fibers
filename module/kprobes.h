#include <linux/kprobes.h>
#include <linux/spinlock.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>

#include <linux/stat.h>
#include <linux/fs.h>
#include <linux/kallsyms.h>

#include "fibers.h"

extern int proc_fiber_base_readdir(struct file *, struct dir_context *);
extern struct dentry *proc_fiber_base_lookup(struct inode *, struct dentry *, unsigned int);
extern void proc_fiber_exit(struct process *);


union proc_op {
								int (*proc_get_link)(struct dentry *, struct path *);
								int (*proc_show)(struct seq_file *m, struct pid_namespace *ns, struct pid *pid, struct task_struct *task);
};

struct pid_entry {
								const char *name;
								unsigned int len;
								umode_t mode;
								const struct inode_operations *iop;
								const struct file_operations *fop;
								union proc_op op;
};


#define NOD(NAME, MODE, IOP, FOP, OP) {     \
																.name = (NAME),         \
																.len  = sizeof(NAME) - 1,     \
																.mode = MODE,         \
																.iop  = IOP,          \
																.fop  = FOP,          \
																.op   = OP,         \
}

#define DIR(NAME, MODE, iops, fops) \
								NOD(NAME, (S_IFDIR|(MODE)), &iops, &fops, {} )
#define REG(NAME, MODE, fops)       \
								NOD(NAME, (S_IFREG|(MODE)), NULL, &fops, {})


struct file_operations file_ops = {
								.read  = generic_read_dir,
								.iterate_shared	= proc_fiber_base_readdir,
								.llseek  = generic_file_llseek,
};

struct inode_operations inode_ops = {
								.lookup = proc_fiber_base_lookup,
};


const struct pid_entry additional[] = {
								DIR("fibers", S_IRUGO|S_IXUGO, inode_ops, file_ops),
};


struct tgid_dir_data {
								struct file *file;
								struct dir_context *ctx;
};

extern struct hlist_head processes;
extern struct process * find_process_by_tgid(pid_t);
extern struct fiber * find_fiber_by_id(pid_t, struct process *);
extern struct thread * find_thread_by_pid(pid_t, struct process *);
extern void do_exit(long);

int clear_thread_struct(struct kprobe *, struct pt_regs *);
int fiber_timer(struct kretprobe_instance *, struct pt_regs *);
int dummy_fnct(struct kretprobe_instance *, struct pt_regs *);
int proc_insert_dir(struct kretprobe_instance *, struct pt_regs *);
int entry_proc_insert_dir(struct kretprobe_instance *, struct pt_regs *);

typedef int (*proc_pident_readdir_t)(struct file *file, struct dir_context *ctx, const struct pid_entry *ents, unsigned int nents);
typedef struct dentry * (*proc_pident_lookup_t)(struct inode *dir, struct dentry *dentry, const struct pid_entry *ents, unsigned int nents);
typedef int (*pid_getattr_t)(const struct path *, struct kstat *, u32, unsigned int);
typedef int (*proc_setattr_t)(struct dentry *dentry, struct iattr *attr);

proc_pident_readdir_t readdir;
proc_pident_lookup_t look;
pid_getattr_t getattr;
proc_setattr_t setattr;


spinlock_t check_nents = __SPIN_LOCK_UNLOCKED(check_nents);
int nents = 0;


struct kprobe do_exit_kp;
struct kretprobe finish_task_switch_krp;
struct kretprobe proc_readdir_krp;
