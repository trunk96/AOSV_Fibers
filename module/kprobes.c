#include <linux/kprobes.h>
#include <linux/proc_fs.h>
#include "fibers.h"

extern struct hlist_head processes;
extern struct process * find_process_by_tgid(pid_t);
extern struct thread * find_thread_by_pid(pid_t, struct process *);
extern void do_exit(long);

int clear_thread_struct(struct kprobe *, struct pt_regs *);

struct kprobe do_exit_kp;


int register_kprobe_do_exit(void){
        do_exit_kp.pre_handler = clear_thread_struct;
        do_exit_kp.addr = (kprobe_opcode_t *)&(do_exit);
        register_kprobe(&do_exit_kp);
        return 0;
}

int unregister_kprobe_do_exit(void){
        unregister_kprobe(&do_exit_kp);
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
                        proc_remove(f->fiber_proc_entry);
                        kfree(f);
                }
                hash_del_rcu(&(p->node));
                kfree(p);
                printk(KERN_DEBUG "[%s] PID %d cleared!\n", KBUILD_MODNAME, current->tgid);
        }
        return 0;
}
