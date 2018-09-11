#include "fibers.h"
#include "init.h"
#include <linux/kernel.h>

DEFINE_HASHTABLE(processes, 10);

long do_ConvertThreadToFiber(pid_t thread_id)
{
        //we have to check if the process is already in our hashtable
        struct process *ep;
        struct thread *gp;
        struct fiber *fp;
        int found = 0;
        hash_for_each_possible_rcu(processes, ep, node, current->tgid){
                if(ep == NULL) {
                        found = 0;
                        break;
                }
                if (ep->process_id == current->tgid) {
                        found = 1;
                        break;
                }
        }
        //if found==0 then it is the first time the process calls our module
        if (!found) {
                init_process(ep, processes);
                init_thread(gp, ep, ep->threads, thread_id);
                init_fiber(fp, ep, ep->fibers);
                printk(KERN_DEBUG "%s created a fiber with fiber id %d", KBUILD_MODNAME, fp->fiber_id);
                return fp->fiber_id;
        }
        //if found==1 then we found the process, and it is saved into e

        found = 0;
        hash_for_each_possible_rcu(ep->threads, gp, node, thread_id){
                if(gp == NULL) {
                        found = 0;
                        break;
                }
                if (gp->thread_id == thread_id) {
                        found = 1;
                        break;
                }
        }

        if (found) {
                printk(KERN_DEBUG "%s Thread with id %d is already a fiber, but it calls ConvertThreadToFiber", KBUILD_MODNAME, thread_id);
                return -1;
        }
        init_thread(gp, ep, ep->threads, thread_id);
        init_fiber(fp, ep, ep->fibers);
        printk(KERN_DEBUG "%s created a fiber with fiber id %d", KBUILD_MODNAME, fp->fiber_id);
        return fp->fiber_id;
}

void * do_CreateFiber(unsigned long stack_size, void *start_address, void *parameters, pid_t thread_id)
{
        printk(KERN_EMERG "CIAO");
        return 100;
}

long do_SwitchToFiber(void * fiber_address, pid_t thread_id)
{
        return 2; //never returns
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
