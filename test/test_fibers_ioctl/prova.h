
typedef void(*user_function_t)(void *param);

struct fiber_arguments {
        //this struct is used in order to pass arguments to the IOCTL call
        //packing all we need in a void*
        unsigned long stack_size;
        user_function_t start_function_address;
        void *start_function_arguments;
        void *fiber_address;
        unsigned long index;
        void *value;
        unsigned long alloc_size;
};
