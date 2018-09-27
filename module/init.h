#define init_process(p, ht) do {                           \
                p = kmalloc(sizeof(struct process), GFP_KERNEL); \
                p->process_id = current->tgid;            \
                atomic64_set(&(p->last_fiber_id), 0);           \
                atomic64_set(&(p->active_threads), 0);    \
                hash_init(p->threads);                    \
                hash_init(p->fibers);                     \
                hash_add_rcu(ht, &(p->node), p->process_id);  \
                proc_fiber_init(p);                       \
} while(0)

#define init_thread(t, parent_process, ht, id) do {       \
                t = kmalloc(sizeof(struct thread), GFP_KERNEL);  \
                t->thread_id = id;                       \
                t->parent = parent_process;                      \
                t->selected_fiber = NULL;                \
                atomic64_inc(&(t->parent->active_threads));  \
                hash_add_rcu(ht, &(t->node), id);         \
} while(0)

#define init_fiber(f, parent, ht, ss, s_ptr) do {        \
                f = kmalloc(sizeof(struct fiber), GFP_KERNEL);  \
                f->fiber_lock = __SPIN_LOCK_UNLOCKED(fiber_lock);        \
                f->attached_thread = NULL;                \
                f->parent_process = parent;       \
                memset((char*)&(f->fpu), 0, sizeof(struct fpu));    \
                memset(f->fls, 0, sizeof(struct fls_data)*MAX_FLS_POINTERS);                 \
                memset(f->fls_bitmap, 0, FLS_BITMAP_SIZE*sizeof(long));                                   \
                memset((char*)&(f->registers), 0, sizeof(struct pt_regs));                            \
                f->fiber_stack = s_ptr; \
                f->fiber_stack_size = (ss >= 0) ? ss : DEFAULT_STACK_SIZE; \
                f->registers.sp = (long)(f->fiber_stack)+((1 << f->fiber_stack_size)*4096)-8; \
                f->registers.bp = f->registers.sp; \
                f->fiber_id = atomic64_inc_return(&(parent->last_fiber_id));  \
                hash_add_rcu(ht, &(f->node), f->fiber_id);                             \
                f->start_address = (void*) task_pt_regs(current)->ip;         \
                f->creator_thread = current->pid;                             \
                f->activation_counter = 0;                                    \
                atomic64_set(&(f->failed_activation_counter), 0);             \
                f->fiber_info.fiber_id = f->fiber_id;                         \
                f->fiber_info.process_id = f->parent_process->process_id;             \
                f->fpu.initialized = 1; \
                copy_fxregs_to_kernel(&(f->fpu));                             \
                f->total_time = 0;  \
                f->prev_time = 0; \
} while(0)

//f->fiber_stack = (void *) __get_free_pages(GFP_USER, f->fiber_stack_size);
