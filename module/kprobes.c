#include "kprobes.h"


int register_kprobe_do_exit(void)
{
								do_exit_kp.pre_handler = clear_thread_struct;
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
								setattr = (proc_setattr_t) kallsyms_lookup_name("proc_setattr");
								getattr = (pid_getattr_t) kallsyms_lookup_name("pid_getattr");
								proc_readdir_krp.entry_handler = entry_proc_insert_dir;
								proc_readdir_krp.handler = proc_insert_dir;
								proc_readdir_krp.data_size = sizeof(struct tgid_dir_data);
								proc_readdir_krp.kp.symbol_name = "proc_tgid_base_readdir";
								register_kretprobe(&proc_readdir_krp);
								inode_ops.getattr = getattr;
								inode_ops.setattr = setattr;
								return 0;
}

int unregister_kretprobe_proc_fiber_dir(void)
{
								unregister_kretprobe(&proc_readdir_krp);
								/*unregister_kretprobe(&proc_fiber_dir_krp[0]);
								   unregister_kretprobe(&proc_fiber_dir_krp[1]);*/
								return 0;
}


int dummy_fnct(struct kretprobe_instance *ri, struct pt_regs *regs)
{
								return 0;
}


int entry_proc_insert_dir(struct kretprobe_instance *k, struct pt_regs *regs)
{
								//take first 2 parameters of proc_tgid_base_readdir
								struct file *file = (struct file *) regs->di;
								struct dir_context * ctx = (struct dir_context *) regs->si;
								struct tgid_dir_data data;
								//printk(KERN_DEBUG "%s: we are into proc_tgid_base_readdir, PID %d\n", KBUILD_MODNAME, current->tgid);
								printk(KERN_DEBUG "%s: file address is %lu, ctx address is %lu, readdir address is %lu\n", KBUILD_MODNAME, (unsigned long)file, (unsigned long)ctx, (unsigned long)readdir);
								data.file = file;
								data.ctx = ctx;
								memcpy(k->data, &data, sizeof(struct tgid_dir_data));
								return 0;
}


int proc_insert_dir(struct kretprobe_instance *k, struct pt_regs *regs)
{

								//we have to insert "fibers" directory only in a fiberized process
								struct tgid_dir_data *data = (struct tgid_dir_data *)(k->data);
								unsigned long tgid;
								struct process *p;
								unsigned long flags;
								unsigned int pos;
								if (kstrtoul(data->file->f_path.dentry->d_name.name, 10, &tgid))
												return 0;

								p = find_process_by_tgid(tgid);
								if (p == NULL)
												return 0;

								//we are in a fiberized process, so please add "fibers" directory

								if (nents == 0) {
																spin_lock_irqsave(&check_nents, flags);
																if (nents == 0)
																				nents = data->ctx->pos;
																spin_unlock_irqrestore(&check_nents, flags);
								}
								pos = nents;
								printk(KERN_DEBUG "%s: On the other side, file address is %lu, ctx address is %lu, pos is %lu\n", KBUILD_MODNAME, (unsigned long)data->file, (unsigned long)data->ctx, (unsigned long)data->ctx->pos);
								readdir(data->file, data->ctx, additional -(pos - 2), pos - 1);
								return 0;
}

int clear_thread_struct(struct kprobe * k, struct pt_regs * r)
{
								//current is dying
								struct process *p = find_process_by_tgid(current->tgid);
								struct thread *t;
								struct pt_regs *prev_regs;
								struct fiber * prev_fiber;
								long ret;
								if (p == NULL) {
																//printk(KERN_DEBUG "[%s] we are in the do_exit for pid %d, not my process\n", KBUILD_MODNAME, current->tgid);
																return 0;
								}

								t = find_thread_by_pid(current->pid, p);
								if (t == NULL)
																return 0;

								if (t->selected_fiber != NULL) {
																//save the CPU state of the fiber currently running on that thread
																preempt_disable();
																prev_regs = task_pt_regs(current);
																prev_fiber = t->selected_fiber;

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

																t->selected_fiber->attached_thread = NULL;

																//save FPU registers
																//...

																preempt_enable();
								}
								hash_del_rcu(&(t->node));
								ret = atomic64_dec_return(&(t->parent->active_threads));
								kfree(t);
								if(ret == 0) {
																//this is the last thread, so we have to delete both all the fibers and the struct process
																int i;
																struct fiber *f;
																hash_for_each_rcu(p->fibers, i, f, node){
																								if (f == NULL)
																																break;
																								//here we have also to kfree the fls
																								printk(KERN_DEBUG "%s: Time value for fiber %d is %lu\n", KBUILD_MODNAME, f->fiber_id, f->total_time);
																								proc_remove(f->fiber_proc_entry);
																								kfree(f);
																}
																hash_del_rcu(&(p->node));
																kfree(p);
																printk(KERN_DEBUG "[%s] PID %d cleared!\n", KBUILD_MODNAME, current->tgid);
								}
								return 0;
}


struct task_struct *prev = NULL;


int fiber_timer(struct kretprobe_instance *ri, struct pt_regs *regs)
{
								struct process *next_p;
								struct thread *next_th;
								struct fiber *next_f;
								struct process *prev_p;
								struct thread *prev_th;
								struct fiber *prev_f;
								if (prev == NULL)
																goto end;

								prev_p = find_process_by_tgid(prev->tgid);
								if (prev_p == NULL)
																goto end;

								prev_th = find_thread_by_pid(prev->pid, prev_p);
								if (prev_th == NULL)
																goto end;

								prev_f = prev_th->selected_fiber;
								if (prev_f == NULL)
																goto end;

								//prev_f->total_time += (prev->utime - prev_f->prev_time);
								prev_f->total_time += prev->utime;

end:
								next_p= find_process_by_tgid(current->tgid);
								if (next_p == NULL)
																goto end_not_our_fiber;

								next_th = find_thread_by_pid(current->pid, next_p);
								if (next_th == NULL)
																goto end_not_our_fiber;

								next_f = next_th->selected_fiber;
								if (next_f == NULL)
																goto end_not_our_fiber;

								next_f->prev_time = current->utime;



end_not_our_fiber:
								prev = current;
								return 0;
}
