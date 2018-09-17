
typedef void(*user_function_t)(void* param);

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
