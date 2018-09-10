#include <linux/hashtable.h>
#include <linux/spinlock.h>
#include <asm/fpu/types.h>
#include <asm/fpu/internal.h>


#define MAX_FLS_POINTERS 256

struct fiber_arguments {
        //this struct is used in order to pass arguments to the IOCTL call
        //packing all we need in a void*
        unsigned long stack_size;
        void *start_function_address;
        void *start_function_arguments;
        void *fiber_address;
        unsigned long index;
        void *value;
        unsigned long alloc_size;
};


struct fls_data {
        void *fls_data;
        unsigned long size;
};


struct fiber {
        //here we have to put all the fields that we want to use in a fiber
        //for example pointer to the stack, saved registers, locks
        //and all the other information we need.
        spinlock_t fiber_lock;
        unsigned long flags;
        unsigned long fiber_id; //key for the hashtable fibers
        struct hlist_node node;
        struct thread *attached_thread; //NULL if no thread executes this fiber
        struct process *parent_process;

        //CPU context
        //...
        struct fpu; //https://elixir.bootlin.com/linux/latest/source/arch/s390/include/asm/fpu/types.h#L14

        struct fls_data fls[MAX_FLS_POINTERS];
        long fls_bitmap[MAX_FLS_POINTERS/sizeof(long)];
};

//typedef struct { long counter; } atomic_long_t; //used to give a new fiber_id each time

struct process {
        //here we have to implement an hash table to mantain all the processes
        //that the module handles in each moment. Each struct process will
        //be linked to a list of struct fiber that belong to that process.

        unsigned long process_id; //key for the hashtable ???
        struct hlist_node node;
        atomic_long_t last_fiber_id;
        struct hlist_head threads;
        struct hlist_head fibers;

};

struct thread {

        unsigned long thread_id; //key for the hashtable threads
        struct hlist_node node;
        struct process *parent;
        struct fiber *selected_fiber;

};


long do_ConvertThreadToFiber(pid_t);
void * do_CreateFiber(unsigned long, void *, void *, pid_t);
long do_SwitchToFiber(void *, pid_t);
unsigned long do_FlsAlloc(unsigned long, pid_t);
long do_FlsFree(unsigned long, pid_t);
void * do_FlsGetValue(unsigned long, pid_t);
long do_FlsSetValue(unsigned long, void *, pid_t);
