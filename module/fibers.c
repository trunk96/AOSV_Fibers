#include "fibers.h"
#include "init.h"
#include <linux/kernel.h>
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
                init_fiber(fp, ep, ep->fibers, -1);
                fp->attached_thread = gp;
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
        init_fiber(fp, ep, ep->fibers, -1);
        fp->attached_thread = gp;
        printk(KERN_DEBUG "%s created a fiber with fiber id %d in process with PID %d\n", KBUILD_MODNAME, fp->fiber_id, fp->parent_process->process_id);
        return fp->fiber_id;
}

void * do_CreateFiber(unsigned long stack_size, user_function_t fiber_function, void __user *parameters, pid_t thread_id)
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
        init_fiber(fp, ep, ep->fibers, stack_size);
        fp->registers.ip = (long) fiber_function;
        fp->registers.di = (long) parameters; //passing the first parameter into %rdi (System V AMD64 ABI)
        printk(KERN_DEBUG "%s created a fiber with fiber id %d in process with PID %d\n", KBUILD_MODNAME, fp->fiber_id, fp->parent_process->process_id);
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
