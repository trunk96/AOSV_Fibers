#import "fibers.h"

long do_ConvertThreadToFiber(void)
{
        return 0;
}

void * do_CreateFiber(unsigned long stack_size, void *start_address, void *parameters)
{
        return 0;
}

long do_SwitchToFiber(void * fiber_address)
{
        return 0;
}

unsigned long do_FlsAlloc(void)
{
        return 0;
}

long do_FlsFree(unsigned long index){
        return 0;
}

void * do_FlsGetValue(unsigned long index)
{
        return 0;
}

long do_FlsSetValue(unsigned long index, void *value)
{
        return 0;
}
