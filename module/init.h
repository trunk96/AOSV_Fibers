#define init_process(p, ht) do {                           \
        p = kmalloc(sizeof(struct process), GFP_KERNEL); \
        p->process_id = current->tgid;            \
        atomic64_set(&(p->last_fiber_id), 0);           \
        atomic64_set(&(p->active_threads), 0);    \
        hash_init(p->threads);                    \
        hash_init(p->fibers);                     \
        hash_add_rcu(ht, &(p->node), p->process_id);  \
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
        memset(f->fls, 0, sizeof(long long)*MAX_FLS_POINTERS);                 \
        bitmap_zero(f->fls_bitmap, MAX_FLS_POINTERS);  \
        memcpy(&f->registers, task_pt_regs(current), sizeof(struct pt_regs)); \
        f->fiber_stack = s_ptr; \
        f->fiber_stack_size = (ss >= 0) ? ss : DEFAULT_STACK_SIZE; \
        f->registers.sp = (long)(f->fiber_stack)+(f->fiber_stack_size)-8; \
        f->registers.bp = f->registers.sp; \
        f->fiber_id = atomic64_inc_return(&(parent->last_fiber_id));  \
        hash_add_rcu(ht, &(f->node), f->fiber_id);                             \
        f->start_address = (void*) task_pt_regs(current)->ip;         \
        f->creator_thread = current->pid;                             \
        f->activation_counter = 0;                                    \
        atomic64_set(&(f->failed_activation_counter), 0);             \
        copy_fxregs_to_kernel(&(f->fpu));                             \
        f->total_time = 0;  \
        snprintf(f->name, 256, "%d", f->fiber_id);                    \
} while(0)
