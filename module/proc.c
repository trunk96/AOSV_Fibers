#include "fibers.h"
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/fs.h>

//extern struct hlist_head processes[2<<10];
extern struct process * find_process_by_tgid(pid_t);
extern struct fiber * find_fiber_by_id(pid_t, struct process *);


ssize_t proc_fiber_read(struct file *, char __user *, size_t, loff_t *);



ssize_t proc_fiber_read(struct file *filp, char __user *buf, size_t len, loff_t *off){
        //build the string
        char string_abc[4096] = "";
        struct proc_info *pinfo;
        void * data = (PDE_DATA(file_inode(filp)));
        if (data == NULL)
                return 0;

        pinfo = (struct proc_info*) data;

        //printk(KERN_DEBUG "%s: proc received PID %d and FID %d\n", KBUILD_MODNAME, pinfo->process_id, pinfo->fiber_id);

        struct process *ep = find_process_by_tgid(pinfo->process_id);

        if (ep == NULL)
                return 0;

        struct fiber *fp = find_fiber_by_id(pinfo->fiber_id, ep);

        if (fp == NULL)
                return 0;

        snprintf(string_abc, 4096, "Currently Ongoing: %s\nStart Address: %lu\nCreator thread: %d\n# of current activations: %lu\n# of failed activations: %lu\nTotal execution time in user space: %lu\n",
                  (fp->attached_thread == NULL)? "no": "yes", (unsigned long)fp->start_address, fp->creator_thread, fp->activation_counter, atomic64_read(&(fp->failed_activation_counter)), fp->total_time/1000000000);

        //printk(KERN_DEBUG "%s: %s\n", KBUILD_MODNAME, string_abc);

        if (*off >= strnlen(string_abc, 4096))
                return 0;
        size_t i = min_t(size_t, len, strnlen(string_abc, 4096));
        if (copy_to_user(buf, string_abc, i)) {
                return -EFAULT;
        }
        *off += i;
        return i;

}
