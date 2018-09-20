#include <linux/kprobes.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include "fibers.h"


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



extern struct hlist_head processes;
extern struct process * find_process_by_tgid(pid_t);
extern struct fiber * find_fiber_by_id(pid_t, struct process *);
extern struct thread * find_thread_by_pid(pid_t, struct process *);
extern void do_exit(long);

int clear_thread_struct(struct kprobe *, struct pt_regs *);
int fiber_timer(struct kretprobe_instance *, struct pt_regs *);


struct kprobe do_exit_kp;
struct kretprobe finish_task_switch_krp;
struct kretprobe proc_fiber_dir_krp[2];



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
        proc_fiber_dir_krp[0].entry_handler = proc_insert_dir;
        proc_fiber_dir_krp[0].handler = dummy_fnct;
        proc_fiber_dir_krp[0].kp.symbol_name = "proc_pident_readdir";
        register_kretprobe(&fproc_fiber_dir_krp[0]);
        proc_fiber_dir_krp[1].entry_handler = proc_insert_dir;
        proc_fiber_dir_krp[1].handler = dummy_fnct;
        proc_fiber_dir_krp[1].kp.symbol_name = "proc_pident_lookup";
        register_kretprobe(&proc_fiber_dir_krp[1]);
        return 0;
}

int unregister_kretprobe_proc_fiber_dir(void)
{
        unregister_kretprobe(&proc_fiber_dir_krp[0]);
        unregister_kretprobe(&proc_fiber_dir_krp[1]);
        return 0;
}


int dummy_fnct(struct kretprobe_instance *ri, struct pt_regs *regs)
{
        return 0;
}


struct pid_entry tgid_base_stuff_modified[ARRAY_SIZE(tgid_base_stuff)+1];

int proc_insert_dir(struct kretprobe_instance *ri, struct pt_regs *regs)
{
        memcpy(tgid_base_stuff_modified, tgid_base_stuff, ARRAY_SIZE(tgid_base_stuff)*sizeof(pid_entry));
        tgid_base_stuff_modified[ARRAY_SIZE(tgid_base_stuff)] = DIR("fibers", S_IRUGO|S_IXUGO, proc_task_inode_operations, proc_task_operations); //TODO
        regs->rdx = tgid_base_stuff_modified;
        regs->rcx += 1;
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
