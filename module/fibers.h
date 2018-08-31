struct fiber_arguments {
        //this struct is used in order to pass arguments to the IOCTL call
        //packing all we need in a void*
        unsigned long stack_size;
        void *start_function_address;
        void *start_function_arguments;
        void *fiber_address;
        unsigned long index;
        void *value;
};


struct fiber{
  //here we have to put all the fields that we want to use in a fiber
  //for example current, pointer to the stack, saved registers, locks
  //and all the other information we need.
};

struct process{
  //here we have to implement an hash table to mantain all the processes
  //that the module handles in each moment. Each struct process will
  //be linked to a list of struct fiber that belong to that process.
};


long do_ConvertThreadToFiber(void);
void * do_CreateFiber(unsigned long, void *, void *);
long do_SwitchToFiber(void *);
unsigned long do_FlsAlloc(void);
long do_FlsFree(unsigned long);
void * do_FlsGetValue(unsigned long);
long do_FlsSetValue(unsigned long, void *);
