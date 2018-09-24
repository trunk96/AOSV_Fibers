#include <linux/kprobes.h>
#include <linux/spinlock.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>

#include <linux/stat.h>
#include <linux/fs.h>
#include <linux/kallsyms.h>

#include "fibers.h"


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
								//.iterate_shared	= proc_fiber_base_readdir,
								.llseek  = generic_file_llseek,
};

struct inode_operations inode_ops;


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


//extern int proc_pident_readdir(struct file *file, struct dir_context *ctx, const struct pid_entry *ents, unsigned int nents);

/*extern struct pid_entry * tgid_base_stuff;
   extern struct dentry *proc_task_lookup(struct inode *, struct dentry *, unsigned int);
   extern int proc_task_getattr(const struct path *, struct kstat *, u32, unsigned int);
   extern int proc_setattr(struct dentry *, struct iattr *);
   extern int proc_pid_permission(struct inode *, int);
   extern int proc_task_readdir(struct file *, struct dir_context *);*/

int clear_thread_struct(struct kprobe *, struct pt_regs *);
int fiber_timer(struct kretprobe_instance *, struct pt_regs *);
int dummy_fnct(struct kretprobe_instance *, struct pt_regs *);
int proc_insert_dir(struct kretprobe_instance *, struct pt_regs *);
int entry_proc_insert_dir(struct kretprobe_instance *, struct pt_regs *);

typedef int (*proc_pident_readdir_t)(struct file *file, struct dir_context *ctx, const struct pid_entry *ents, unsigned int nents);
typedef struct dentry * (*proc_pident_lookup_t)(struct inode *dir, struct dentry *dentry, const struct pid_entry *ents, unsigned int nents);

proc_pident_readdir_t readdir;
proc_pident_lookup_t look;

spinlock_t check_nents = __SPIN_LOCK_UNLOCKED(check_nents);
int nents = 0;


struct kprobe do_exit_kp;
struct kretprobe finish_task_switch_krp;
struct kretprobe proc_fiber_dir_krp[2];
struct kretprobe proc_readdir_krp;



int register_kprobe_do_exit(void)
{
								do_exit_kp.pre_handler = clear_thread_struct;
								do_exit_kp.addr = (kprobe_opcode_t *)&(do_exit);
								register_kprobe(&do_exit_kp);
								return 0;
}

int unregister_kprobe_do_exit(void)
{
								unregister_kprobe(&do_exit_kp);
								return 0;
}

int register_kretprobe_finish_task_switch(void)
{
								finish_task_switch_krp.handler = fiber_timer;
								finish_task_switch_krp.kp.symbol_name = "finish_task_switch";
								register_kretprobe(&finish_task_switch_krp);
								return 0;
}

int unregister_kretprobe_finish_task_switch(void)
{
								unregister_kretprobe(&finish_task_switch_krp);
								return 0;
}



int register_kretprobe_proc_fiber_dir(void)
{
								/*proc_fiber_dir_krp[0].entry_handler = dummy_fnct;
								   proc_fiber_dir_krp[0].handler = dummy_fnct;
								   proc_fiber_dir_krp[0].kp.symbol_name = "proc_pident_readdir";
								   register_kretprobe(&proc_fiber_dir_krp[0]);
								   proc_fiber_dir_krp[1].entry_handler = dummy_fnct;
								   proc_fiber_dir_krp[1].handler = dummy_fnct;
								   proc_fiber_dir_krp[1].kp.symbol_name = "proc_pident_lookup";
								   register_kretprobe(&proc_fiber_dir_krp[1]);
								   read = (proc_pident_readdir_t) proc_fiber_dir_krp[0].kp.addr;
								   look = (proc_pident_lookup_t) proc_fiber_dir_krp[1].kp.addr;*/
								readdir = (proc_pident_readdir_t) kallsyms_lookup_name("proc_pident_readdir");
								proc_readdir_krp.entry_handler = entry_proc_insert_dir;
								proc_readdir_krp.handler = proc_insert_dir;
								proc_readdir_krp.data_size = sizeof(struct tgid_dir_data);
								proc_readdir_krp.kp.symbol_name = "proc_tgid_base_readdir";

								/*unregister_kretprobe(&proc_fiber_dir_krp[0]);
								   unregister_kretprobe(&proc_fiber_dir_krp[1]);*/
								register_kretprobe(&proc_readdir_krp);
								return 0;
}

int unregister_kretprobe_proc_fiber_dir(void)
{
								unregister_kretprobe(&proc_readdir_krp);
								/*unregister_kretprobe(&proc_fiber_dir_krp[0]);
								   unregister_kretprobe(&proc_fiber_dir_krp[1]);*/
								return 0;
}


int dummy_fnct(struct kretprobe_instance *ri, struct pt_regs *regs)
{
								return 0;
}


//struct pid_entry tgid_base_stuff_modified[ARRAY_SIZE(tgid_base_stuff)+1];
//ssize_t tgid_base_stuff_size = sizeof(tgid_base_stuff)/sizeof(struct pid_entry);
//struct pid_entry tgid_base_stuff_modified[(sizeof(tgid_base_stuff)/sizeof(struct pid_entry))+1];

/*static const struct inode_operations proc_fiber_inode_operations = {
   .lookup		= proc_task_lookup,
   .getattr	= proc_task_getattr,
   .setattr	= proc_setattr,
   .permission	= proc_pid_permission,
   };

   static const struct file_operations proc_fiber_operations = {
   .read		= generic_read_dir,
   .iterate_shared	= proc_task_readdir,
   .llseek		= generic_file_llseek,
   };*/

//extern const struct pid_entry *additional;

int entry_proc_insert_dir(struct kretprobe_instance *k, struct pt_regs *regs)
{
								/*memcpy(tgid_base_stuff_modified, tgid_base_stuff, tgid_base_stuff_size*sizeof(struct pid_entry));
								   struct pid_entry new_entry = DIR("fibers", S_IRUGO|S_IXUGO, proc_fiber_inode_operations, proc_fiber_operations);
								   tgid_base_stuff_modified[tgid_base_stuff_size] = new_entry; //TODO
								   regs->dx = tgid_base_stuff_modified;
								   regs->cx += 1;*/

								//take first 2 parameters of proc_tgid_base_readdir
								struct file *file = (struct file *) regs->di;
								struct dir_context * ctx = (struct dir_context *) regs->si;
								//printk(KERN_DEBUG "%s: we are into proc_tgid_base_readdir, PID %d\n", KBUILD_MODNAME, current->tgid);
								printk(KERN_DEBUG "%s: file address is %lu, ctx address is %lu, readdir address is %lu\n", KBUILD_MODNAME, (unsigned long)file, (unsigned long)ctx, (unsigned long)readdir);
								struct tgid_dir_data data = {
																.file = file,
																.ctx = ctx,
								};
								memcpy(k->data, &data, sizeof(struct tgid_dir_data));
								return 0;
}


int proc_insert_dir(struct kretprobe_instance *k, struct pt_regs *regs)
{


								struct tgid_dir_data *data = (struct tgid_dir_data *)(k->data);
								unsigned long flags;
								if (nents == 0) {
																spin_lock_irqsave(&check_nents, flags);
																nents = data->ctx->pos;
																spin_unlock_irqrestore(&check_nents, flags);
								}
								unsigned int pos = nents;
								printk(KERN_DEBUG "%s: On the other side, file address is %lu, ctx address is %lu, pos is %lu\n", KBUILD_MODNAME, (unsigned long)data->file, (unsigned long)data->ctx, (unsigned long)data->ctx->pos);
								//read(data->file, data->ctx, (unsigned long)(additional) - ((pos - 2)*sizeof(struct pid_entry)), pos-1);
								readdir(data->file, data->ctx, additional -(pos - 2), pos - 1);
								//data->ctx->pos--;
								/*unsigned int nents = pos - 1;
								   struct pid_entry *ents = additional - (pos - 2);
								   struct pid_entry *p;
								   for (p = ents + (data->ctx->pos - 2); p < ents + nents; p++) {
								        //printk(KERN_DEBUG "%s: additional address is %lu, p address is %lu\n", KBUILD_MODNAME, (unsigned long) additional, (unsigned long) p);
								        printk(KERN_DEBUG "%s: Directory name is %s\n", KBUILD_MODNAME, p->name);
								   }*/
								return 0;
}

int clear_thread_struct(struct kprobe * k, struct pt_regs * r)
{
								//current is dying
								struct process *p = find_process_by_tgid(current->tgid);
								if (p == NULL) {
																//printk(KERN_DEBUG "[%s] we are in the do_exit for pid %d, not my process\n", KBUILD_MODNAME, current->tgid);
																return 0;
								}

								struct thread *t = find_thread_by_pid(current->pid, p);
								if (t == NULL)
																return 0;

								if (t->selected_fiber != NULL) {
																//save the CPU state of the fiber currently running on that thread
																preempt_disable();
																struct pt_regs *prev_regs = task_pt_regs(current);
																struct fiber * prev_fiber = t->selected_fiber;

																//save previous CPU registers in the previous fiber
																prev_fiber->registers.r15 = prev_regs->r15;
																prev_fiber->registers.r14 = prev_regs->r14;
																prev_fiber->registers.r13 = prev_regs->r13;
																prev_fiber->registers.r12 = prev_regs->r12;
																prev_fiber->registers.r11 = prev_regs->r11;
																prev_fiber->registers.r10 = prev_regs->r10;
																prev_fiber->registers.r9 = prev_regs->r9;
																prev_fiber->registers.r8 = prev_regs->r8;
																prev_fiber->registers.ax = prev_regs->ax;
																prev_fiber->registers.bx = prev_regs->bx;
																prev_fiber->registers.cx = prev_regs->cx;
																prev_fiber->registers.dx = prev_regs->dx;
																prev_fiber->registers.si = prev_regs->si;
																prev_fiber->registers.di = prev_regs->di;
																prev_fiber->registers.sp = prev_regs->sp;
																prev_fiber->registers.bp = prev_regs->bp;
																prev_fiber->registers.ip = prev_regs->ip;

																t->selected_fiber->attached_thread = NULL;

																//save FPU registers
																//...

																preempt_enable();
								}
								hash_del_rcu(&(t->node));
								long ret = atomic64_dec_return(&(t->parent->active_threads));
								kfree(t);
								if(ret == 0) {
																//this is the last thread, so we have to delete both all the fibers and the struct process
																int i;
																struct fiber *f;
																hash_for_each_rcu(p->fibers, i, f, node){
																								if (f == NULL)
																																break;
																								//here we have also to kfree the fls
																								printk(KERN_DEBUG "%s: Time value for fiber %d is %lu\n", KBUILD_MODNAME, f->fiber_id, f->total_time);
																								proc_remove(f->fiber_proc_entry);
																								kfree(f);
																}
																hash_del_rcu(&(p->node));
																kfree(p);
																printk(KERN_DEBUG "[%s] PID %d cleared!\n", KBUILD_MODNAME, current->tgid);
								}
								return 0;
}


struct task_struct *prev = NULL;


int fiber_timer(struct kretprobe_instance *ri, struct pt_regs *regs)
{
								struct process *next_p;
								struct thread *next_th;
								struct fiber *next_f;
								if (prev == NULL)
																goto end;

								struct process *prev_p = find_process_by_tgid(prev->tgid);
								if (prev_p == NULL)
																goto end;

								struct thread *prev_th = find_thread_by_pid(prev->pid, prev_p);
								if (prev_th == NULL)
																goto end;

								struct fiber *prev_f = prev_th->selected_fiber;
								if (prev_f == NULL)
																goto end;

								//prev_f->total_time += (prev->utime - prev_f->prev_time);
								prev_f->total_time += prev->utime;

end:
								next_p= find_process_by_tgid(current->tgid);
								if (next_p == NULL)
																goto end_not_our_fiber;

								next_th = find_thread_by_pid(current->pid, next_p);
								if (next_th == NULL)
																goto end_not_our_fiber;

								next_f = next_th->selected_fiber;
								if (next_f == NULL)
																goto end_not_our_fiber;

								next_f->prev_time = current->utime;



end_not_our_fiber:
								prev = current;
								return 0;
}
