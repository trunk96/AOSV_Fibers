struct fiber_arguments {
        unsigned long stack_size;
        void *start_function_address;
        void *start_function_arguments;
        void *fiber_address;
        unsigned long index;
        void *value;
};


long do_ConvertThreadToFiber(void);
void * do_CreateFiber(unsigned long, void *, void *);
long do_SwitchToFiber(void *);
unsigned long do_FlsAlloc(void);
long do_FlsFree(unsigned long);
void * do_FlsGetValue(unsigned long);
long do_FlsSetValue(unsigned long, void *);
