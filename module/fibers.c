#include "fibers.h"
#include "init.h"
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/proc_fs.h>


DEFINE_HASHTABLE(processes, 10);

spinlock_t struct_process_lock = __SPIN_LOCK_UNLOCKED(struct_process_lock);
unsigned long struct_process_flags;


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


pid_t do_ConvertThreadToFiber(pid_t thread_id)
{
        //we have to check if the process is already in our hashtable
        struct process *ep;
        struct thread *gp;
        struct fiber *fp;

        //Check if struct process already exists in an atomic way
        spin_lock_irqsave(&(struct_process_lock), struct_process_flags);
        ep = find_process_by_tgid(current->tgid);
        if (ep == NULL) {
                init_process(ep, processes);
                printk(KERN_DEBUG "%s: PID %d now using fibers\n", KBUILD_MODNAME, ep->process_id);
        }
        spin_unlock_irqrestore(&(struct_process_lock), struct_process_flags);

        //Now the struct process exists and we can convert the thread, if not already fiber

        gp = find_thread_by_pid(thread_id, ep);
        if (gp != NULL)
                return -1;
        init_thread(gp, ep, ep->threads, thread_id);
        init_fiber(fp, ep, ep->fibers, -1, 0);

        //these two lines to override init_fiber behaviour in case of a yet existing line of execution
        fp->registers.sp = task_pt_regs(current)->sp;
        fp->registers.bp = task_pt_regs(current)->bp;

        //this line to override the behaviour of init_fiber
        fp->activation_counter++;


        fp->attached_thread = gp;
        gp->selected_fiber = fp;

        return fp->fiber_id;
}

pid_t do_CreateFiber(void *stack_pointer, unsigned long stack_size, user_function_t fiber_function, void __user *parameters, pid_t thread_id)
{
        struct process *ep;
        struct thread *gp;
        struct fiber *fp;

        ep = find_process_by_tgid(current->tgid);
        if (ep == NULL)
                return -1;

        gp = find_thread_by_pid(thread_id, ep);
        if (gp == NULL)
                return -1;

        //we are sure that the thread calling CreateFiber is a fiber, so we can create a new fiber
        init_fiber(fp, ep, ep->fibers, stack_size, stack_pointer);
        fp->registers.ip = (long) fiber_function;
        fp->registers.di = (long) parameters; //passing the first parameter into %rdi (System V AMD64 ABI)

        //this line to override the behaviour of init_fiber
        fp->start_address = (void*) fiber_function;

        return fp->fiber_id;
}

long do_SwitchToFiber(pid_t fiber_id, pid_t thread_id)
{
        struct process *ep;
        struct thread *tp;
        struct fiber *f;
        struct fiber * prev_fiber;
        struct pt_regs *prev_regs;
        struct fpu *prev_fpu;
        struct fpu *next_fpu;
        struct fxregs_state * next_fx_regs;

        ep = find_process_by_tgid(current->tgid);

        if(ep == NULL)
                return -1;

        tp = find_thread_by_pid(thread_id, ep);

        if (tp == NULL)
                return -1;

        f = find_fiber_by_id(fiber_id, ep);

        if (f == NULL)
                return -1;

        if (f->attached_thread != NULL) {
                atomic64_inc(&(f->failed_activation_counter));
                return -1;
        }
        f->attached_thread = tp;
        f->activation_counter++;

        prev_fiber = tp->selected_fiber;
        tp->selected_fiber = f;

        prev_fiber->total_time += current->utime;


        //save previous CPU registers in the previous fiber
        prev_regs = task_pt_regs(current);
        memcpy(&prev_fiber->registers, prev_regs, sizeof(struct pt_regs));

        //save previous FPU registers in the previous fiber
        prev_fpu = &(prev_fiber->fpu);
        copy_fxregs_to_kernel(prev_fpu);

        //detach fiber from current thread
        prev_fiber->attached_thread = NULL;

        //restore next CPU context from the next fiber
        memcpy(prev_regs, &f->registers, sizeof(struct pt_regs));

        //restore next FPU registers of the next fiber
        next_fpu = &(f->fpu);
        next_fx_regs = &(next_fpu->state.fxsave);
        copy_kernel_to_fxregs(next_fx_regs);

        return 0;
}

long do_FlsAlloc(pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        struct thread *t;
        struct fiber *f;
        long index;

        if (p == NULL)
                return -1;

        t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return -1;

        f = t->selected_fiber;

        //there is room for an allocation
        index = find_first_zero_bit(f->fls_bitmap, MAX_FLS_POINTERS);
        if (index == MAX_FLS_POINTERS)
        {
                printk(KERN_DEBUG "%s: FlsAlloc has no index free for fiber %d, PID %d\n", KBUILD_MODNAME, f->fiber_id, f->parent_process->process_id);
                return -1;
        }

        change_bit(index, f->fls_bitmap);
        return index;
}

bool do_FlsFree(long index, pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        struct thread *t;
        struct fiber *f;

        if (p == NULL)
                return false;

        t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return false;

        f = t->selected_fiber;

        if (index >= MAX_FLS_POINTERS || index < 0)
                return false;

        if(test_bit(index, f->fls_bitmap) == 0)
                return false;

        change_bit(index, f->fls_bitmap);

        return true;
}

long long do_FlsGetValue(long index, pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        struct thread *t;
        struct fiber *f;

        if (p == NULL)
                return -1;

        t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return -1;

        f = t->selected_fiber;

        if (index >= MAX_FLS_POINTERS || index < 0)
                return -1;

        if(test_bit(index, f->fls_bitmap) == 0)
                return -1;

        return f->fls[index];
}

void do_FlsSetValue(long index, long long value, pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        struct thread *t;
        struct fiber *f;

        if (p == NULL)
                return;

        t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return;

        f = t->selected_fiber;

        if (index >= MAX_FLS_POINTERS || index < 0)
                return;

        if(test_bit(index, f->fls_bitmap) == 0)
                return;

        f->fls[index] = value;

        return;
}



int process_cleanup(){
        //this function removes all the current process's structures
        struct process *p = find_process_by_tgid(current->tgid);
        struct thread *t;
        struct fiber *f;
        int i;


        if (p == NULL) {
                return 0;
        }
        hash_for_each_rcu(p->threads, i, t, node){
                kfree(t);
        }
        hash_for_each_rcu(p->fibers, i, f, node){
                kfree(f);
        }
        hash_del_rcu(&(p->node));
        kfree(p);
        printk(KERN_DEBUG "%s: Cleanup for PID %d successfully done at process_cleanup!\n", KBUILD_MODNAME, current->tgid);
        return 0;
}
