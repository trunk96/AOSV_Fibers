#include <linux/string.h>
#include "fibers.h"


void init_process(struct process * p, struct hlist_head h)
{
          p->process_id = current->tgid;
          p->last_fiber_id->counter = 0;
          DEFINE_HASHTABLE(t, 8);
          p->threads = t;
          DEFINE_HASHTABLE(f, 8);
          p->fibers = f;

          hash_add_rcu(h, p->node, p->process_id);

          return;
}

void init_thread(struct thread *t, struct process *parent, struct hlist_head h, pid_t id)
{
          t->thread_id = id;
          t->parent = parent;
          t->selected_fiber = NULL;

          hash_add_rcu(h, t->node, id);

          return;
}


void init_fiber(struct fiber *f, struct process *parent_process, struct list_head h)
{
        f->fiber_lock = SPINLOCK_UNLOCKED;
        f->attached_thread = NULL;
        f->parent_process = parent_process;

        memset(f->fpu, 0, sizeof(struct fpu));
        memset(f->fls, 0, sizeof(fls_data)*MAX_FLS_POINTERS);
        memset(f->fls_bitmap, 0, FLS_BITMAP_SIZE);

        f->fiber_id = atomic64_inc_return(&(parent_process->last_fiber_id));

        hash_add_rcu(h, f->node, f->fiber_id);
}
