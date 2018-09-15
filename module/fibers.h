#include <linux/hashtable.h>
#include <linux/spinlock.h>
#include <asm/fpu/types.h>
#include <asm/fpu/internal.h>
#include <linux/string.h>
#include <asm/processor.h>


#define MAX_FLS_POINTERS 256
#define FLS_BITMAP_SIZE MAX_FLS_POINTERS/(8*sizeof(long))
#define H_SZ 1024
#define DEFAULT_STACK_SIZE 1


typedef void(*user_function_t)(void *param);


struct fiber_arguments {
        //this struct is used in order to pass arguments to the IOCTL call
        //packing all we need in a void*
        void *stack_pointer;
        unsigned long stack_size;
        user_function_t start_function_address;
        void *start_function_arguments;
        pid_t fiber_id;
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
        pid_t fiber_id; //key for the hashtable fibers
        struct hlist_node node;
        struct thread *attached_thread; //NULL if no thread executes this fiber
        struct process *parent_process;


        //CPU context
        //...
        struct pt_regs registers; //copy of the pt_regs struct that points into the kernel level stack
        struct fpu fpu; // to replace in task_struct->struct_thread->fpu upon context switch
        /*https://elixir.bootlin.com/linux/latest/source/arch/x86/include/asm/fpu/types.h/*/


        void *fiber_stack;
        unsigned long fiber_stack_size;

        struct fls_data fls[MAX_FLS_POINTERS];
        long fls_bitmap[FLS_BITMAP_SIZE];
};


struct process {
        //here we have to implement an hash table to mantain all the processes
        //that the module handles in each moment. Each struct process will
        //be linked to a list of struct fiber that belong to that process.

        pid_t process_id; //key for the hashtable ???
        struct hlist_node node;
        atomic_long_t last_fiber_id;
        DECLARE_HASHTABLE(threads, 10);
        DECLARE_HASHTABLE(fibers, 10);

};

struct thread {

        pid_t thread_id; //key for the hashtable threads
        struct hlist_node node;
        struct process *parent;
        struct fiber *selected_fiber;

};


void * do_ConvertThreadToFiber(pid_t);
void * do_CreateFiber(void *, unsigned long, user_function_t, void *, pid_t);
long do_SwitchToFiber(pid_t, pid_t);
unsigned long do_FlsAlloc(unsigned long, pid_t);
long do_FlsFree(unsigned long, pid_t);
void * do_FlsGetValue(unsigned long, pid_t);
long do_FlsSetValue(unsigned long, void *, pid_t);







//void init_process(struct process *, struct hlist_head *);
//void init_thread(struct thread *, struct process *, struct hlist_head *, pid_t);
//void init_fiber(struct fiber *, struct process *, struct list_head *);
