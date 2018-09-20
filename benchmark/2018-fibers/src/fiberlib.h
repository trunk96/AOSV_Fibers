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

const int tab64[64] = {
    63,  0, 58,  1, 59, 47, 53,  2,
    60, 39, 48, 27, 54, 33, 42,  3,
    61, 51, 37, 40, 49, 18, 28, 20,
    55, 30, 34, 11, 43, 14, 22,  4,
    62, 57, 46, 52, 38, 26, 32, 41,
    50, 36, 17, 19, 29, 10, 13, 21,
    56, 45, 25, 31, 35, 16,  9, 12,
    44, 24, 15,  8, 23,  7,  6,  5};

int log2_64 (unsigned long value)
{
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    value |= value >> 32;
    return tab64[((unsigned long)((value - (value >> 1))*0x07EDD5E59A4E28C2)) >> 58];
}
#endif
