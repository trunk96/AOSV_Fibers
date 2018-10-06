#ifndef LIB
#define LIB


#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

typedef enum IOCTL_TYPE {
        IOCTL_CONVERT_THREAD_TO_FIBER=0,
        IOCTL_CREATE_FIBER,
        IOCTL_SWITCH_TO_FIBER,
        IOCTL_FLS_ALLOC,
        IOCTL_FLS_FREE,
        IOCTL_FLS_GETVALUE,
        IOCTL_FLS_SETVALUE
} ioctl_type_t;

typedef void (*user_function_t)(void* param);


int fiberlib_initialized = 0;
int fd;
long ioctl_numbers[7]={0};

struct fiber_arguments {
        //this struct is used in order to pass arguments to the IOCTL call
        //packing all we need in a void*
        void *stack_pointer;
        unsigned long stack_size;
        user_function_t start_function_address;
        void *start_function_arguments;
        pid_t fiber_id;
        unsigned long index;
        unsigned long buffer;
        unsigned long alloc_size;
};

#endif
