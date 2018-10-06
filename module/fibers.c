#include "fibers.h"
#include "init.h"
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/proc_fs.h>


DEFINE_HASHTABLE(processes, 10);
//is the same of struct hlist_head processes[2<<10] = {...};

spinlock_t struct_process_lock = __SPIN_LOCK_UNLOCKED(struct_process_lock);
unsigned long struct_process_flags;



struct process * find_process_by_tgid(pid_t tgid)
{
        int found = 0;
        struct process *ep;
        hash_for_each_possible_rcu(processes, ep, node, tgid){
                if(ep == NULL) {
                        found = 0;
                        break;
                }
                if (ep->process_id == tgid) {
                        found = 1;
                        break;
                }
        }
        if (found)
                return ep;
        return NULL;
}


struct thread * find_thread_by_pid(pid_t pid, struct process *ep)
{
        int found = 0;
        struct thread *tp;
        hash_for_each_possible_rcu(ep->threads, tp, node, pid){
                if(tp == NULL) {
                        found = 0;
                        break;
                }
                if (tp->thread_id == pid) {
                        found = 1;
                        break;
                }
        }
        if (found)
                return tp;
        return NULL;

}

struct fiber * find_fiber_by_id(pid_t fiber_id, struct process *ep)
{
        int found = 0;
        struct fiber *fp;
        hash_for_each_possible_rcu(ep->fibers, fp, node, fiber_id){
                if(fp == NULL) {
                        found = 0;
                        break;
                }
                if (fp->fiber_id == fiber_id) {
                        found = 1;
                        break;
                }
        }
        if (found)
                return fp;
        return NULL;
}


pid_t do_ConvertThreadToFiber(pid_t thread_id)
{
        //we have to check if the process is already in our hashtable
        struct process *ep;
        struct thread *gp;
        struct fiber *fp;
        char name[256] = "";
/*
        ep = find_process_by_tgid(current->tgid);
        //if ep==NULL then it is the first time the process calls our module
        if (ep == NULL) {
                init_process(ep, processes);
                init_thread(gp, ep, ep->threads, thread_id);
                init_fiber(fp, ep, ep->fibers, -1, 0);

                //these two lines to override init_fiber behaviour in case of a yet existing line of execution
                fp->registers.sp = task_pt_regs(current)->sp;
                fp->registers.bp = task_pt_regs(current)->bp;

                fp->attached_thread = gp;
                gp->selected_fiber = fp;

                //this line to override the behaviour of init_fiber
                fp->activation_counter++;

                fp->prev_time = current->utime;

                //create the proc directory for the process
                char name[256] = "";
                //snprintf(name, 256, "%d", current->tgid);
                //struct proc_dir_entry *proc_parent = proc_mkdir(name, NULL);
                //ep->proc_entry = proc_mkdir("fibers", proc_parent);


                snprintf(name, 256, "%d_%d",ep->process_id, fp->fiber_id);
                //fp->fiber_proc_entry = proc_create_data(name, 0, NULL, &fops, &(fp->fiber_info));
                fp->fiber_proc_entry = proc_create_data(name, 0, ep->proc_fiber, &fops, &(fp->fiber_info));
                //fp->fiber_proc_entry = proc_create("name_1", 0, NULL, &fops);

                printk(KERN_DEBUG "[%s] created a fiber with fiber id %d in process with PID %d\n", KBUILD_MODNAME, fp->fiber_id, fp->parent_process->process_id);
                return fp->fiber_id;
        }
*/

		//Check if struct process already exists in an atomic way
		    spin_lock_irqsave(&(struct_process_lock), struct_process_flags);
        ep = find_process_by_tgid(current->tgid);
        if (ep == NULL) {
                init_process(ep, processes);
        }
        spin_unlock_irqrestore(&(struct_process_lock), struct_process_flags);

        //Now the struct process exists and we can convert the thread, if not already fiber

        gp = find_thread_by_pid(thread_id, ep);
        if (gp != NULL) {
                printk(KERN_DEBUG "[%s] Thread with id %d is already a fiber, but it calls ConvertThreadToFiber\n", KBUILD_MODNAME, thread_id);
                return -1;
        }
        init_thread(gp, ep, ep->threads, thread_id);
        init_fiber(fp, ep, ep->fibers, -1, 0);

        //these two lines to override init_fiber behaviour in case of a yet existing line of execution
        fp->registers.sp = task_pt_regs(current)->sp;
        fp->registers.bp = task_pt_regs(current)->bp;

        //this line to override the behaviour of init_fiber
        fp->activation_counter++;

        fp->prev_time = current->utime;

        fp->attached_thread = gp;
        gp->selected_fiber = fp;

        /*snprintf(name, 256, "%d", current->tgid);
        struct proc_dir_entry *proc_parent = proc_mkdir(name, NULL);
        ep->proc_entry = proc_mkdir("fibers", proc_parent);*/


        //snprintf(name, 256, "%d_%d",ep->process_id, fp->fiber_id);
        /*ep->fiber_base_stuff[fp->fiber_id - 1].name = fp->name;
        ep->fiber_base_stuff[fp->fiber_id - 1].len = sizeof(name) - 1;
        ep->fiber_base_stuff[fp->fiber_id - 1].mode = S_IFREG|S_IRUGO;
        ep->fiber_base_stuff[fp->fiber_id - 1].iop = NULL;
        ep->fiber_base_stuff[fp->fiber_id - 1].fop = &f_fops;*/

        //fp->fiber_proc_entry = proc_create_data(name, 0, NULL, &fops, &(fp->fiber_info));
        //fp->fiber_proc_entry = proc_create_data(name, 0, ep->proc_fiber, &fops, &(fp->fiber_info));

        printk(KERN_DEBUG "%s: created a fiber with fiber id %d in process with PID %d\n", KBUILD_MODNAME, fp->fiber_id, fp->parent_process->process_id);
        return fp->fiber_id;
}

pid_t do_CreateFiber(void *stack_pointer, unsigned long stack_size, user_function_t fiber_function, void __user *parameters, pid_t thread_id)
{
        struct process *ep;
        struct thread *gp;
        struct fiber *fp;
        char name[256] = "";
        ep = find_process_by_tgid(current->tgid);
        if (ep == NULL) {
                return -2;  //-2 means that the thread calling CreateFiber is not a fiber itself.
        }

        gp = find_thread_by_pid(thread_id, ep);
        if (gp == NULL) {
                return -2; //-2 means that the thread calling CreateFiber is not a fiber itself.
        }

        //we are sure that the thread calling CreateFiber is a fiber, so we can create a new fiber
        init_fiber(fp, ep, ep->fibers, stack_size, stack_pointer);
        fp->registers.ip = (long) fiber_function;
        fp->registers.di = (long) parameters; //passing the first parameter into %rdi (System V AMD64 ABI)

        //this line to override the behaviour of init_fiber
        fp->start_address = (void*) fiber_function;

        /*struct file_operations fops = {
                .open = proc_fiber_open,
                .read = proc_fiber_read,
        };

        char name[256] = "";
        snprintf(name, 256, "%d", fp->fiber_id);
        struct proc_info pinfo = {
                .fiber_id = fp->fiber_id,
                .process_id = ep->process_id,
        };
        void * data = NULL;
        memcpy(&data, &pinfo, sizeof(void*));
        fp->fiber_proc_entry = proc_create_data(name, 0666, ep->proc_entry, &fops, data);*/

        //snprintf(name, 256, "%d_%d",ep->process_id, fp->fiber_id);
        //fp->fiber_proc_entry = proc_create_data(name, 0, ep->proc_fiber, &fops, &(fp->fiber_info));
        /*ep->fiber_base_stuff[fp->fiber_id - 1].name = fp->name;
        ep->fiber_base_stuff[fp->fiber_id - 1].len = sizeof(name) - 1;
        ep->fiber_base_stuff[fp->fiber_id - 1].mode = S_IFREG|S_IRUGO;
        ep->fiber_base_stuff[fp->fiber_id - 1].iop = NULL;
        ep->fiber_base_stuff[fp->fiber_id - 1].fop = &f_fops;*/


        printk(KERN_DEBUG "%s: created a fiber with fiber id %d in process with PID %d\n", KBUILD_MODNAME, fp->fiber_id, fp->parent_process->process_id);
        return fp->fiber_id;
}

long do_SwitchToFiber(pid_t fiber_id, pid_t thread_id)
{

        unsigned long flags;
        struct process *ep;
        struct thread *tp;
        struct fiber *f;
        struct fiber * prev_fiber;
        struct pt_regs *prev_regs;
        struct fpu *prev_fpu;
        struct fpu *next_fpu;
        struct fxregs_state * next_fx_regs;

        ep = find_process_by_tgid(current->tgid);

        if(ep == NULL)
                return -1;

        tp = find_thread_by_pid(thread_id, ep);

        if (tp == NULL)
                return -1;

        f = find_fiber_by_id(fiber_id, ep);

        if (f == NULL)
                return -1;

        //spin_lock_irqsave(&(f->fiber_lock), flags);
        //critical section
        if (f->attached_thread != NULL){
                atomic64_inc(&(f->failed_activation_counter));
                return -1;
        }
        f->attached_thread = tp;
        f->activation_counter++;

        prev_fiber = tp->selected_fiber;
        tp->selected_fiber = f;
        //end of critical section
        //spin_unlock_irqrestore(&(f->fiber_lock), flags);


        //printk(KERN_DEBUG "%s exited from critical section\n", KBUILD_MODNAME);



        //prev_fiber->total_time += (current->utime-prev_fiber->prev_time);
        prev_fiber->total_time += current->utime;

        f->prev_time = current->utime;

        //kernel_fpu_begin();
        //preempt_disable();

        prev_regs = task_pt_regs(current);


        //save previous CPU registers in the previous fiber
        /*prev_fiber->registers.r15 = prev_regs->r15;
        prev_fiber->registers.r14 = prev_regs->r14;
        prev_fiber->registers.r13 = prev_regs->r13;
        prev_fiber->registers.r12 = prev_regs->r12;
        prev_fiber->registers.r11 = prev_regs->r11;
        prev_fiber->registers.r10 = prev_regs->r10;
        prev_fiber->registers.r9 = prev_regs->r9;
        prev_fiber->registers.r8 = prev_regs->r8;
        prev_fiber->registers.ax = prev_regs->ax;
        prev_fiber->registers.bx = prev_regs->bx;
        prev_fiber->registers.cx = prev_regs->cx;
        prev_fiber->registers.dx = prev_regs->dx;
        prev_fiber->registers.si = prev_regs->si;
        prev_fiber->registers.di = prev_regs->di;
        prev_fiber->registers.sp = prev_regs->sp;
        prev_fiber->registers.bp = prev_regs->bp;
        prev_fiber->registers.ip = prev_regs->ip;
        prev_fiber->registers.flags = prev_regs->flags;*/
        memcpy(&prev_fiber->registers, prev_regs, sizeof(struct pt_regs));

        prev_fiber->attached_thread = NULL;

        //save previous FPU registers in the previous fiber
        /*struct fpu *prev_fpu = &(current->thread.fpu);
           memcpy(&(prev_fiber->fpu), prev_fpu, sizeof(struct fpu));*/
        //fpu__save(&(prev_fiber->fpu));

        /*if (!copy_fpregs_to_fpstate(&(prev_fiber->fpu))) {
                copy_kernel_to_fpregs(&(prev_fiber->fpu.state));
        }*/
        prev_fpu = &(prev_fiber->fpu);
        copy_fxregs_to_kernel(prev_fpu);

        //restore next CPU context from the next fiber
        /*prev_regs->r15 = f->registers.r15;
        prev_regs->r14 = f->registers.r14;
        prev_regs->r13 = f->registers.r13;
        prev_regs->r12 = f->registers.r12;
        prev_regs->r11 = f->registers.r11;
        prev_regs->r10 = f->registers.r10;
        prev_regs->r9 = f->registers.r9;
        prev_regs->r8 = f->registers.r8;
        prev_regs->ax = f->registers.ax;
        prev_regs->bx = f->registers.bx;
        prev_regs->cx = f->registers.cx;
        prev_regs->dx = f->registers.dx;
        prev_regs->si = f->registers.si;
        prev_regs->di = f->registers.di;
        prev_regs->sp = f->registers.sp;
        prev_regs->bp = f->registers.bp;
        prev_regs->ip = f->registers.ip;
        prev_regs->flags = f->registers.flags;*/
        memcpy(prev_regs, &f->registers, sizeof(struct pt_regs));


        //tp->selected_fiber = f;

        /*//restore next FPU registers of the next fiber
           struct fpu *next_fpu = &(f->fpu);
           memcpy(prev_fpu, next_fpu, sizeof(struct fpu));
           struct fpu *next_fpu = &(f->fpu);*/
        /*struct fpu *next_fpu = &(f->fpu);
        fpu__restore(next_fpu);*/

        next_fpu = &(f->fpu);
        next_fx_regs = &(next_fpu->state.fxsave);
        copy_kernel_to_fxregs(next_fx_regs);

        /*fpregs_activate(next_fpu);
	      copy_kernel_to_fpregs(&(next_fpu->state));*/

        //preempt_enable();

        printk(KERN_DEBUG "%s: Successfully switched from fiber %d to fiber %d\n", KBUILD_MODNAME, prev_fiber->fiber_id, f->fiber_id);

        return 0;
}

long do_FlsAlloc(pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        struct thread *t;
        struct fiber *f;
        int counter = 0;
        long index;

        if (p == NULL)
                return -1;
        t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return -1;
        f = t->selected_fiber;

        //there is room for an allocation
        index = find_first_zero_bit(f->fls_bitmap, MAX_FLS_POINTERS);
        if (index == MAX_FLS_POINTERS)
        {
          printk(KERN_DEBUG "%s: FlsAlloc has no index free for fiber %d\n", KBUILD_MODNAME, f->fiber_id);
          return -1;
        }

        change_bit(index, f->fls_bitmap);
        printk(KERN_DEBUG "%s: FlsAlloc gives index %ld to fiber %d\n", KBUILD_MODNAME, index, f->fiber_id);
        return index;
}

bool do_FlsFree(long index, pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        struct thread *t;
        struct fiber *f;
        printk(KERN_DEBUG "%s: Trying to free index %ld for a fiber\n", KBUILD_MODNAME, index);

        if (p == NULL)
                return false;
        t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return false;
        f = t->selected_fiber;

        if (index >= MAX_FLS_POINTERS || index < 0)
                return false;

        if(test_bit(index, f->fls_bitmap) == 0)
                return false;

        change_bit(index, f->fls_bitmap);

        printk(KERN_DEBUG "%s: Freed index %ld for fiber %d\n", KBUILD_MODNAME, index, f->fiber_id);
        return true;
}

long long do_FlsGetValue(long index, pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        struct thread *t;
        struct fiber *f;

        if (p == NULL)
                return -1;
        t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return -1;
        f = t->selected_fiber;

        if (index >= MAX_FLS_POINTERS || index < 0)
                return -1;

        if(test_bit(index, f->fls_bitmap) == 0)
                return -1;

        printk(KERN_DEBUG "%s: FlsGetValue returns value %lld to fiber %d\n", KBUILD_MODNAME, f->fls[index], f->fiber_id);

        return f->fls[index];
}

void do_FlsSetValue(long index, long long value, pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        struct thread *t;
        struct fiber *f;

        if (p == NULL)
                return;
        t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return;
        f = t->selected_fiber;
        //printk(KERN_DEBUG "%s: Index given from PID %d is %ld\n", KBUILD_MODNAME, p->process_id, index);

        if (index >= MAX_FLS_POINTERS || index < 0)
                return;

        if(test_bit(index, f->fls_bitmap) == 0)
                return;

        f->fls[index] = value;

        printk(KERN_DEBUG "%s: Received value %lld from fiber %d to index %ld\n", KBUILD_MODNAME, f->fls[index], f->fiber_id, index);
        return;
}
