#include "fiberlib.h"
#include "fiberlib_user.h"

void fiberlib_init()
{
        fd = open("/dev/fibers", O_RDONLY);
        char buf[256];
        long ret = read(fd, buf, sizeof(buf));
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
        double foo = 0.0;
        foo += 0.05;
        return;
}


void* ConvertThreadToFiber()
{
		pid_t pid;
        if (!fiberlib_initialized)
                fiberlib_init();
        pid = ioctl(fd, ioctl_numbers[IOCTL_CONVERT_THREAD_TO_FIBER], 0);
        return (void*) pid;
}


void * CreateFiber(void (*entry_point)(void *), unsigned long stack_size, void *parameters)
{
		user_function_t *function_pointer = (user_function_t *)entry_point;
		pid_t pid;
        if (!fiberlib_initialized)
                fiberlib_init();
        //stack_size is espressed in pages but the kernel wants an order
        int stack_size_kernel = log2_64(stack_size);
        if (2<<stack_size_kernel != stack_size)
                stack_size_kernel++;
        struct fiber_arguments f = {
                .stack_size = stack_size_kernel,
                .start_function_address = function_pointer,
                .start_function_arguments = parameters,
        };
        //f.stack_pointer = malloc((4096<<stack_size_kernel)*sizeof(char));
        posix_memalign(&(f.stack_pointer), 16, (4096<<stack_size_kernel)*sizeof(char));
        bzero(f.stack_pointer, (4096<<stack_size_kernel)*sizeof(char));
        //printf("Stack address is %p\n", f.stack_pointer);
        pid = ioctl(fd, ioctl_numbers[IOCTL_CREATE_FIBER], &f);
        return (void *) pid;
}


void SwitchToFiber(void * fiber_id)
{
		pid_t pid;
		memcpy(&pid, &fiber_id, sizeof(pid_t));
        if (!fiberlib_initialized)
                fiberlib_init();
        struct fiber_arguments f = {
                .fiber_id = fiber_id,
        };
        ioctl(fd, ioctl_numbers[IOCTL_SWITCH_TO_FIBER], &f);
        return;
}


long FlsAlloc()
{
		unsigned long size = sizeof(long long);
        if (!fiberlib_initialized)
                fiberlib_init();
        struct fiber_arguments f = {
                .alloc_size = size,
        };
        return ioctl(fd, ioctl_numbers[IOCTL_FLS_ALLOC], &f);
}


long FlsFree(unsigned long index)
{
        if (!fiberlib_initialized)
                fiberlib_init();
        struct fiber_arguments f = {
                .index = index,
        };
        return ioctl(fd, ioctl_numbers[IOCTL_FLS_ALLOC], &f);
}


void FlsSetValue(long long value, unsigned long index)
{
		long long * buffer = &value;
        if (!fiberlib_initialized)
                fiberlib_init();
        struct fiber_arguments f = {
                .index = index,
                .buffer = (unsigned long) buffer,
        };
        ioctl(fd, ioctl_numbers[IOCTL_FLS_SETVALUE], &f);
        return;
}

long long FlsGetValue(unsigned long index)
{
		long long * buffer = malloc(sizeof(long long));
        if (!fiberlib_initialized)
                fiberlib_init();
        struct fiber_arguments f = {
                .index = index,
                .buffer = (unsigned long) buffer,
        };
        ioctl(fd, ioctl_numbers[IOCTL_FLS_GETVALUE], &f);
        return *buffer;
}
