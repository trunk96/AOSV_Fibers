#include "fibers.h"
#include "init.h"
#include <linux/kernel.h>
#include <linux/sched.h>
#include <asm/switch_to.h>




DEFINE_HASHTABLE(processes, 10);


struct process * find_process_by_tgid(pid_t tgid)
{
        int found = 0;
        struct process *ep;
        hash_for_each_possible_rcu(processes, ep, node, tgid){
                if(ep == NULL) {
                        found = 0;
                        break;
                }
                if (ep->process_id == tgid) {
                        found = 1;
                        break;
                }
        }
        if (found)
                return ep;
        return NULL;
}


struct thread * find_thread_by_pid(pid_t pid, struct process *ep)
{
        int found = 0;
        struct thread *tp;
        hash_for_each_possible_rcu(ep->threads, tp, node, pid){
                if(tp == NULL) {
                        found = 0;
                        break;
                }
                if (tp->thread_id == pid) {
                        found = 1;
                        break;
                }
        }
        if (found)
                return tp;
        return NULL;

}

struct fiber * find_fiber_by_id(pid_t fiber_id, struct process *ep)
{
        int found = 0;
        struct fiber *fp;
        hash_for_each_possible_rcu(ep->fibers, fp, node, fiber_id){
                if(fp == NULL) {
                        found = 0;
                        break;
                }
                if (fp->fiber_id == fiber_id) {
                        found = 1;
                        break;
                }
        }
        if (found)
                return fp;
        return NULL;
}

void * do_ConvertThreadToFiber(pid_t thread_id)
{
        //we have to check if the process is already in our hashtable
        struct process *ep;
        struct thread *gp;
        struct fiber *fp;
        ep = find_process_by_tgid(current->tgid);
        //if ep==NULL then it is the first time the process calls our module
        if (ep == NULL) {
                init_process(ep, processes);
                init_thread(gp, ep, ep->threads, thread_id);
                init_fiber(fp, ep, ep->fibers, -1, 0);

                //these two lines to override init_fiber behaviour in case of a yet existing line of execution
                fp->registers.sp = task_pt_regs(current)->sp;
                fp->registers.bp = task_pt_regs(current)->bp;

                fp->attached_thread = gp;
                gp->selected_fiber = fp;
                printk(KERN_DEBUG "%s created a fiber with fiber id %d in process with PID %d\n", KBUILD_MODNAME, fp->fiber_id, fp->parent_process->process_id);
                return fp->fiber_id;
        }
        //if ep!=NULL then we found the process

        gp = find_thread_by_pid(thread_id, ep);
        if (gp != NULL) {
                printk(KERN_DEBUG "%s Thread with id %d is already a fiber, but it calls ConvertThreadToFiber\n", KBUILD_MODNAME, thread_id);
                return -1;
        }
        init_thread(gp, ep, ep->threads, thread_id);
        init_fiber(fp, ep, ep->fibers, -1, 0);

        //these two lines to override init_fiber behaviour in case of a yet existing line of execution
        fp->registers.sp = task_pt_regs(current)->sp;
        fp->registers.bp = task_pt_regs(current)->bp;

        fp->attached_thread = gp;
        gp->selected_fiber = fp;
        printk(KERN_DEBUG "[%s] created a fiber with fiber id %d in process with PID %d\n", KBUILD_MODNAME, fp->fiber_id, fp->parent_process->process_id);
        return fp->fiber_id;
}

void * do_CreateFiber(void *stack_pointer, unsigned long stack_size, user_function_t fiber_function, void __user *parameters, pid_t thread_id)
{
        struct process *ep;
        struct thread *gp;
        struct fiber *fp;
        ep = find_process_by_tgid(current->tgid);
        if (ep == NULL) {
                return -2;  //-2 means that the thread calling CreateFiber is not a fiber itself.
        }

        gp = find_thread_by_pid(thread_id, ep);
        if (gp == NULL) {
                return -2; //-2 means that the thread calling CreateFiber is not a fiber itself.
        }

        //we are sure that the thread calling CreateFiber is a fiber, so we can create a new fiber
        init_fiber(fp, ep, ep->fibers, stack_size, stack_pointer);
        fp->registers.ip = (long) fiber_function;
        fp->registers.di = (long) parameters; //passing the first parameter into %rdi (System V AMD64 ABI)
        printk(KERN_DEBUG "[%s] created a fiber with fiber id %d in process with PID %d\n", KBUILD_MODNAME, fp->fiber_id, fp->parent_process->process_id);
        return fp->fiber_id;
}

long do_SwitchToFiber(pid_t fiber_id, pid_t thread_id)
{

        unsigned long flags;
        struct process *ep;
        struct thread *tp;

        ep = find_process_by_tgid(current->tgid);

        if(ep == NULL)
                return -1;

        tp = find_thread_by_pid(thread_id, ep);

        if (tp == NULL)
                return -1;

        struct fiber *f = find_fiber_by_id(fiber_id, ep);

        if (f == NULL)
                return -1;

        spin_lock_irqsave(&(f->fiber_lock), flags);
        //critical section
        if (f->attached_thread != NULL)
                return -1;
        f->attached_thread = tp;
        //end of critical section
        spin_unlock_irqrestore(&(f->fiber_lock), flags);
        printk(KERN_DEBUG "%s exited from critical section\n", KBUILD_MODNAME);


        /* note - this code may work, if not ask to Alessandro Pellegrini*/

        //kernel_fpu_begin();
        preempt_disable();
        struct pt_regs *prev_regs = task_pt_regs(current);
        struct fiber * prev_fiber = tp->selected_fiber;

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

        tp->selected_fiber->attached_thread = NULL;

        /*//save previous FPU registers in the previous fiber
           struct fpu *prev_fpu = &(current->thread.fpu);
           memcpy(&(prev_fiber->fpu), prev_fpu, sizeof(struct fpu));*/

        //restore next CPU context from the next fibers_read
        prev_regs->r15 = f->registers.r15;
        prev_regs->r14 = f->registers.r14;
        prev_regs->r13 = f->registers.r13;
        prev_regs->r12 = f->registers.r12;
        prev_regs->r11 = f->registers.r11;
        prev_regs->r10 = f->registers.r10;
        prev_regs->r9 = f->registers.r9;
        prev_regs->r8 = f->registers.r8;
        prev_regs->ax = f->registers.ax;
        prev_regs->bx = f->registers.bx;
        prev_regs->cx = f->registers.cx;
        prev_regs->dx = f->registers.dx;
        prev_regs->si = f->registers.si;
        prev_regs->di = f->registers.di;
        prev_regs->sp = f->registers.sp;
        prev_regs->bp = f->registers.bp;
        prev_regs->ip = f->registers.ip;

        tp->selected_fiber = f;

        preempt_enable();

        return 0;
}

unsigned long do_FlsAlloc(unsigned long alloc_size, pid_t thread_id)
{
        return 3;
}

long do_FlsFree(unsigned long index, pid_t thread_id)
{
        return 4;
}

void * do_FlsGetValue(unsigned long index, pid_t thread_id)
{
        return 5;
}

long do_FlsSetValue(unsigned long index, void *value, pid_t thread_id)
{
        return 6;
}
