#include "fibers.h"
#include <linux/kernel.h>

long do_ConvertThreadToFiber(pid_t thread_id)
{
        return thread_id;
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
