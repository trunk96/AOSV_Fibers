#include "kprobes.h"
#include <linux/smp.h>

int register_kprobe_do_exit(void)
{
				do_exit_kp.pre_handler = exit_cleanup;
				do_exit_kp.addr = (kprobe_opcode_t *)&(do_exit);
				register_kprobe(&do_exit_kp);
				return 0;
}

int unregister_kprobe_do_exit(void)
{
				unregister_kprobe(&do_exit_kp);
				return 0;
}

int register_kretprobe_finish_task_switch(void)
{
				finish_task_switch_krp.handler = fiber_timer;
				finish_task_switch_krp.kp.symbol_name = "finish_task_switch";
				register_kretprobe(&finish_task_switch_krp);
				return 0;
}

int unregister_kretprobe_finish_task_switch(void)
{
				unregister_kretprobe(&finish_task_switch_krp);
				return 0;
}


int register_kretprobe_proc_fiber_dir(void)
{
				readdir = (proc_pident_readdir_t) kallsyms_lookup_name("proc_pident_readdir");
				look = (proc_pident_lookup_t) kallsyms_lookup_name("proc_pident_lookup");
				setattr = (proc_setattr_t) kallsyms_lookup_name("proc_setattr");
				getattr = (pid_getattr_t) kallsyms_lookup_name("pid_getattr");
				proc_readdir_krp.entry_handler = entry_proc_insert_dir;
				proc_readdir_krp.handler = proc_insert_dir;
				proc_readdir_krp.data_size = sizeof(struct tgid_dir_data);
				proc_readdir_krp.kp.symbol_name = "proc_tgid_base_readdir";
				proc_lookup_krp.entry_handler = entry_proc_lookup_dir;
				proc_lookup_krp.handler = proc_lookup_dir;
				proc_lookup_krp.data_size = sizeof(struct tgid_lookup_data);
				proc_lookup_krp.kp.symbol_name = "proc_tgid_base_lookup";
				register_kretprobe(&proc_readdir_krp);
				register_kretprobe(&proc_lookup_krp);
				inode_ops.getattr = getattr;
				inode_ops.setattr = setattr;
				return 0;
}

int unregister_kretprobe_proc_fiber_dir(void)
{
				unregister_kretprobe(&proc_readdir_krp);
				unregister_kretprobe(&proc_lookup_krp);
				return 0;
}

int entry_proc_lookup_dir(struct kretprobe_instance *k, struct pt_regs *regs)
{
	//take first 2 parameters of proc_tgid_base_lookup
	struct inode *inode = (struct inode *) regs->di;
	struct dentry *dentry = (struct dentry *) regs->si;
	struct tgid_lookup_data data;
	data.inode = inode;
	data.dentry = dentry;
	memcpy(k->data, &data, sizeof(struct tgid_lookup_data));
	return 0;
}


int proc_lookup_dir(struct kretprobe_instance *k, struct pt_regs *regs)
{
	//we have to insert "fibers" directory only in a fiberized process
	struct tgid_lookup_data *data = (struct tgid_lookup_data *)(k->data);
	struct process *p;
	//unsigned long flags;
	unsigned int pos;
	struct task_struct * task = get_proc_task(data->inode);

	p = find_process_by_tgid(task->tgid);
	if (p == NULL)
					return 0;

	//we are in a fiberized process, so please add "fibers" directory

	if (nents == 0) {
					return 0;
	}
	pos = nents;
	look(data->inode, data->dentry, additional - (pos - 2), pos - 1);

	return 0;
}


int entry_proc_insert_dir(struct kretprobe_instance *k, struct pt_regs *regs)
{
				//take first 2 parameters of proc_tgid_base_readdir
				struct file *file = (struct file *) regs->di;
				struct dir_context * ctx = (struct dir_context *) regs->si;
				struct tgid_dir_data data;
				data.file = file;
				data.ctx = ctx;
				memcpy(k->data, &data, sizeof(struct tgid_dir_data));
				return 0;
}


int proc_insert_dir(struct kretprobe_instance *k, struct pt_regs *regs)
{

				//we have to insert "fibers" directory only in a fiberized process
				struct tgid_dir_data *data = (struct tgid_dir_data *)(k->data);
				struct process *p;
				unsigned long flags;
				unsigned int pos;
				struct task_struct * task = get_pid_task(proc_pid(file_inode(data->file)), PIDTYPE_PID);

				if (nents == 0) {
								spin_lock_irqsave(&check_nents, flags);
								if (nents == 0)
												nents = data->ctx->pos;
								spin_unlock_irqrestore(&check_nents, flags);
				}

				p = find_process_by_tgid(task->tgid);
				if (p == NULL)
								return 0;

				//we are in a fiberized process, so please add "fibers" directory

				pos = nents;
				readdir(data->file, data->ctx, additional - (pos - 2), pos - 1);
				return 0;
}

int exit_cleanup(struct kprobe * k, struct pt_regs * r)
{
				//current is dying
				struct process *p = find_process_by_tgid(current->tgid);
				struct thread *t;
				struct pt_regs *prev_regs;
				struct fiber * prev_fiber;
				struct fpu *prev_fpu;
				long ret;
				if (p == NULL) {
								return 0;
				}

				t = find_thread_by_pid(current->pid, p);
				if (t == NULL)
								return 0;

				ret = atomic64_dec_return(&(t->parent->active_threads));

				if (t->selected_fiber != NULL && ret != 0) {
								//save the CPU state of the fiber currently running on that thread
								preempt_disable();
								prev_regs = task_pt_regs(current);
								prev_fiber = t->selected_fiber;

								//save previous CPU registers in the previous fiber
								memcpy(&prev_fiber->registers, prev_regs, sizeof(struct pt_regs));

								//save FPU registers
								prev_fpu = &(prev_fiber->fpu);
				        copy_fxregs_to_kernel(prev_fpu);

								t->selected_fiber->attached_thread = NULL;

								preempt_enable();
				}
				hash_del_rcu(&(t->node));
				kfree(t);
				if(ret == 0) {
								//this is the last thread, so we have to delete both all the fibers and the struct process
								int i;
								struct fiber *f;
								hash_for_each_rcu(p->fibers, i, f, node){
																if (f == NULL)
																								break;
																kfree(f);
								}
								hash_del_rcu(&(p->node));
								kfree(p);
								printk(KERN_DEBUG "%s: Cleanup for PID %d successfully done!\n", KBUILD_MODNAME, current->tgid);
				}
				return 0;
}


DEFINE_PER_CPU(struct task_struct *, prev_task) = NULL;


int fiber_timer(struct kretprobe_instance *ri, struct pt_regs *regs)
{
				struct process *next_p;
				struct thread *next_th;
				struct fiber *next_f;
				struct process *prev_p;
				struct thread *prev_th;
				struct fiber *prev_f;
				struct task_struct * prev;

				prev = get_cpu_var(prev_task);

				if (prev == NULL){
								printk(KERN_DEBUG "%s: prev is NULL\n", KBUILD_MODNAME);
								put_cpu_var(prev_task);
								goto end;
				}
				printk(KERN_DEBUG "%s: ID is %d, prev is %d AND current is %d\n", KBUILD_MODNAME, smp_processor_id(), prev->tgid, current->tgid);
				prev_p = find_process_by_tgid(prev->tgid);
				if (prev_p == NULL){
								put_cpu_var(prev_task);
								goto end;
				}

				prev_th = find_thread_by_pid(prev->pid, prev_p);


				if (prev_th == NULL)
								goto end;

				prev_f = prev_th->selected_fiber;
				if (prev_f == NULL)
								goto end;

				prev_f->total_time += prev->utime;

				put_cpu_var(prev_task);

end:
			/*	next_p = find_process_by_tgid(current->tgid);
				if (next_p == NULL)
								goto end_not_our_fiber;

				next_th = find_thread_by_pid(current->pid, next_p);
				if (next_th == NULL)
								goto end_not_our_fiber;

				next_f = next_th->selected_fiber;
				if (next_f == NULL)
								goto end_not_our_fiber;

				next_f->prev_time = current->utime;

*/

end_not_our_fiber:
				prev = get_cpu_var(prev_task);
				//prev_task = current;
				this_cpu_write(prev_task, current);
				put_cpu_var(prev_task);
				return 0;
}
