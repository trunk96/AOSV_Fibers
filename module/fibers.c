#include "fibers.h"
#include "init.h"
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/bitmap.h>
#include <linux/proc_fs.h>


DEFINE_HASHTABLE(processes, 10);
//is the same of struct hlist_head processes[2<<10];


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

                //create the proc directory for the process
                char name[256] = "";
                /*snprintf(name, 256, "%d", current->tgid);
                struct proc_dir_entry *proc_parent = proc_mkdir(name, NULL);
                ep->proc_entry = proc_mkdir("fibers", proc_parent);*/

                snprintf(name, 256, "%d/fibers", current->tgid);
                printk(KERN_DEBUG "[%s] String name is \"%s\"\n", KBUILD_MODNAME, name);
                ep->proc_entry = proc_mkdir(name, NULL);
                struct file_operations fops = {
                        .open = proc_fiber_open,
                        .read = proc_fiber_read,
                };
                snprintf(name, 256, "%d", fp->fiber_id);
                struct proc_info pinfo = {
                        .fiber_id = fp->fiber_id,
                        .process_id = ep->process_id,
                };
                void * data = NULL;
                memcpy(&data, &pinfo, sizeof(void*));
                fp->fiber_proc_entry = proc_create_data(name, 0666, ep->proc_entry, &fops, data);

                printk(KERN_DEBUG "[%s] created a fiber with fiber id %d in process with PID %d\n", KBUILD_MODNAME, fp->fiber_id, fp->parent_process->process_id);
                return fp->fiber_id;
        }
        //if ep!=NULL then we found the process

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

        fp->attached_thread = gp;
        gp->selected_fiber = fp;
        printk(KERN_DEBUG "[%s] created a fiber with fiber id %d in process with PID %d\n", KBUILD_MODNAME, fp->fiber_id, fp->parent_process->process_id);
        return fp->fiber_id;
}

pid_t do_CreateFiber(void *stack_pointer, unsigned long stack_size, user_function_t fiber_function, void __user *parameters, pid_t thread_id)
{
        struct process *ep;
        struct thread *gp;
        struct fiber *fp;
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

        struct file_operations fops = {
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
        fp->fiber_proc_entry = proc_create_data(name, 0666, ep->proc_entry, &fops, data);


        printk(KERN_DEBUG "[%s] created a fiber with fiber id %d in process with PID %d\n", KBUILD_MODNAME, fp->fiber_id, fp->parent_process->process_id);
        return fp->fiber_id;
}

long do_SwitchToFiber(pid_t fiber_id, pid_t thread_id)
{

        unsigned long flags;
        struct process *ep;
        struct thread *tp;

        ep = find_process_by_tgid(current->tgid);

        if(ep == NULL)
                return -1;

        tp = find_thread_by_pid(thread_id, ep);

        if (tp == NULL)
                return -1;

        struct fiber *f = find_fiber_by_id(fiber_id, ep);

        if (f == NULL)
                return -1;

        spin_lock_irqsave(&(f->fiber_lock), flags);
        //critical section
        if (f->attached_thread != NULL){
                atomic64_inc(&(f->failed_activation_counter));
                return -1;
        }
        f->attached_thread = tp;
        f->activation_counter++;
        //end of critical section
        spin_unlock_irqrestore(&(f->fiber_lock), flags);
        //printk(KERN_DEBUG "%s exited from critical section\n", KBUILD_MODNAME);


        /* note - this code may work, if not ask to Alessandro Pellegrini*/

        //kernel_fpu_begin();
        preempt_disable();
        struct pt_regs *prev_regs = task_pt_regs(current);
        struct fiber * prev_fiber = tp->selected_fiber;

        //save previous CPU registers in the previous fiber
        prev_fiber->registers.r15 = prev_regs->r15;
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

        tp->selected_fiber->attached_thread = NULL;

        //save previous FPU registers in the previous fiber
        /*struct fpu *prev_fpu = &(current->thread.fpu);
           memcpy(&(prev_fiber->fpu), prev_fpu, sizeof(struct fpu));
           fpu__save(&(prev_fiber->fpu));*/

        //restore next CPU context from the next fiber
        prev_regs->r15 = f->registers.r15;
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

        tp->selected_fiber = f;

        /*//restore next FPU registers of the next fiber
           struct fpu *next_fpu = &(f->fpu);
           memcpy(prev_fpu, next_fpu, sizeof(struct fpu));
           struct fpu *next_fpu = &(f->fpu);
           fpu__restore(next_fpu);*/

        preempt_enable();
        printk(KERN_DEBUG "[%s] Successfully switched to fiber %d\n", KBUILD_MODNAME, f->fiber_id);

        return 0;
}

long do_FlsAlloc(unsigned long alloc_size, pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        if (p == NULL)
                return -1;
        struct thread *t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return -1;
        struct fiber *f = t->selected_fiber;
        int counter = 0;
        while(counter < FLS_BITMAP_SIZE && (long)f->fls_bitmap[counter] == -1) {
                counter++;
        }
        if (counter >= FLS_BITMAP_SIZE)
                return -1;

        //there is room for an allocation
        unsigned long index = find_first_zero_bit(f->fls_bitmap, FLS_BITMAP_SIZE*sizeof(unsigned long)*64);
        change_bit(index, f->fls_bitmap);
        f->fls[index].fls_data = kmalloc(alloc_size*sizeof(char), GFP_USER);
        f->fls[index].size = alloc_size;
        printk(KERN_DEBUG "[%s] Index for PID %d is %ld\n", KBUILD_MODNAME, p->process_id, index);
        return index;
}

long do_FlsFree(unsigned long index, pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        if (p == NULL)
                return -1;
        struct thread *t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return -1;
        struct fiber *f = t->selected_fiber;

        if (index >= MAX_FLS_POINTERS || index < 0)
                return -1;

        if(test_bit(index, f->fls_bitmap) == 0)
                return -1;

        kfree(f->fls[index].fls_data);
        f->fls[index].size = 0;

        change_bit(index, f->fls_bitmap);

        printk(KERN_DEBUG "[%s] Freed index %ld for PID %d\n", KBUILD_MODNAME, index, p->process_id);
        return 0;
}

long do_FlsGetValue(unsigned long index, unsigned long buffer, pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        if (p == NULL)
                return -1;
        struct thread *t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return -1;
        struct fiber *f = t->selected_fiber;

        if (index >= MAX_FLS_POINTERS || index < 0)
                return -1;

        if(test_bit(index, f->fls_bitmap) == 0)
                return -1;

        if (!access_ok(VERIFY_WRITE, buffer, f->fls[index].size * sizeof(char))) {
                return -EFAULT;
        }
        if (copy_to_user((void*)buffer, f->fls[index].fls_data, f->fls[index].size)) {
                return -EFAULT;
        }

        printk(KERN_DEBUG "[%s] Returning a value to PID %d\n", KBUILD_MODNAME, p->process_id);

        return f->fls[index].size;
}

long do_FlsSetValue(unsigned long index, unsigned long value, pid_t thread_id)
{
        struct process *p = find_process_by_tgid(current->tgid);
        if (p == NULL)
                return -1;
        struct thread *t = find_thread_by_pid(thread_id, p);
        if (t == NULL || t->selected_fiber == NULL)
                return -1;
        struct fiber *f = t->selected_fiber;
        printk(KERN_DEBUG "[%s] Index given from PID %d is %ld\n", KBUILD_MODNAME, p->process_id, index);

        if (index >= MAX_FLS_POINTERS || index < 0)
                return -1;

        if(test_bit(index, f->fls_bitmap) == 0)
                return -1;

        if (!access_ok(VERIFY_READ, value, f->fls[index].size * sizeof(char))) {
                return -EFAULT;
        }
        if (copy_from_user(f->fls[index].fls_data, (void*)value, f->fls[index].size*sizeof(char))) {
                return -EFAULT;
        }

        printk(KERN_DEBUG "[%s] Received value from PID %d\n", KBUILD_MODNAME, p->process_id);
        return 0;
}
