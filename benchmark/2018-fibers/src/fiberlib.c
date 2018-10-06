#include "fiberlib.h"
#include "fiberlib_user.h"



__attribute__((constructor)) void fiberlib_init()
{
        fd = open("/dev/fibers", O_RDONLY);
        char buf[256];
        read(fd, buf, sizeof(buf));
        char *token;
        char *ptr;
        const char delimiter[2]="\n";

        token = strtok(buf, delimiter);
        int i = 0;

        while(token != NULL) {

                ioctl_numbers[i] = strtol(token, &ptr, 10);
                token = strtok(NULL, delimiter);
                i++;
        }
        fiberlib_initialized = 1;
        return;
}

__attribute__((destructor)) void close_fiberlib()
{
    close(fd);
    return;
}


pid_t ConvertThreadToFiber()
{
        if (!fiberlib_initialized)
                fiberlib_init();
        return (pid_t) ioctl(fd, ioctl_numbers[IOCTL_CONVERT_THREAD_TO_FIBER], 0);
}


pid_t CreateFiber(user_function_t function_pointer, unsigned long stack_size, void *parameters)
{
        if (!fiberlib_initialized)
                fiberlib_init();
        //stack_size is espressed in pages but the kernel wants an order
        /*int stack_size_kernel = log2_64(stack_size);
           if (2<<stack_size_kernel != stack_size)
                stack_size_kernel++;*/
        struct fiber_arguments f = {
                .stack_size = stack_size,
                .start_function_address = function_pointer,
                .start_function_arguments = parameters,
        };
        //f.stack_pointer = malloc((4096<<stack_size_kernel)*sizeof(char));
        posix_memalign(&(f.stack_pointer), 16, stack_size);
        bzero(f.stack_pointer, stack_size);
        //printf("Stack address is %p\n", f.stack_pointer);
        return (pid_t) ioctl(fd, ioctl_numbers[IOCTL_CREATE_FIBER], &f);
}


long SwitchToFiber(pid_t fiber_id)
{
        if (!fiberlib_initialized)
                fiberlib_init();
        struct fiber_arguments f = {
                .fiber_id = fiber_id,
        };
        return ioctl(fd, ioctl_numbers[IOCTL_SWITCH_TO_FIBER], &f);
}


long FlsAlloc()
{
        if (!fiberlib_initialized)
                fiberlib_init();
        return ioctl(fd, ioctl_numbers[IOCTL_FLS_ALLOC], 0);
}


bool FlsFree(long index)
{
        if (!fiberlib_initialized)
                fiberlib_init();
        struct fiber_arguments f = {
                .index = index,
        };
        return ioctl(fd, ioctl_numbers[IOCTL_FLS_FREE], &f);
}


void FlsSetValue(long long buffer, long index)
{
        if (!fiberlib_initialized)
                fiberlib_init();
        struct fiber_arguments f = {
                .index = index,
                .buffer = buffer,
        };
        ioctl(fd, ioctl_numbers[IOCTL_FLS_SETVALUE], &f);
        return;
}

long long FlsGetValue(long index)
{
        if (!fiberlib_initialized)
                fiberlib_init();
        long long a = 0;
        struct fiber_arguments f = {
                .index = index,
                .buffer = (unsigned long)&a,
        };
        //printf("Someone wants to get it's fls value at index %ld\n", index);

        ioctl(fd, ioctl_numbers[IOCTL_FLS_GETVALUE], &f);
        //printf("Returned value to userspace is %lu\n", a);
        return a;
}
