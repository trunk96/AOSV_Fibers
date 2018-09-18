#include "fibers.h"
#include <linux/proc_fs.h>

extern struct hlist_head processes[2<<10];

int proc_fiber_open(struct inode *, struct file *);
ssize_t proc_fiber_read(struct file *, char __user *, size_t, loff_t *);


int proc_fiber_open(struct inode *inode, struct file *filp)
{
        void *data = PDE_DATA(inode);
        memcpy(&(filp->private_data), &data, sizeof(void *));
        return 0;
}

ssize_t proc_fiber_read(struct file *filp, char __user *buf, size_t len, loff_t *off){
        //build the string
        char string_message[4096] = "";
        struct proc_info pinfo;
        memcpy(&pinfo, &(filp->private_data), sizeof(struct proc_info));

        int found = 0;
        struct process *ep;
        hash_for_each_possible_rcu(processes, ep, node, pinfo.process_id){
                if(ep == NULL) {
                        found = 0;
                        break;
                }
                if (ep->process_id == pinfo.process_id) {
                        found = 1;
                        break;
                }
        }
        if (!found)
                return 0;

        found = 0;
        struct fiber *fp;
        hash_for_each_possible_rcu(ep->fibers, fp, node, pinfo.fiber_id){
                if(fp == NULL) {
                        found = 0;
                        break;
                }
                if (fp->fiber_id == pinfo.fiber_id) {
                        found = 1;
                        break;
                }
        }
        if (!found)
                return 0;

        snprintf(string_message, 4096, "Currently Ongoing: %s\nStart Address: %lu\nCreator thread: %d\n# of current activations: %lu\n# of failed activations: %lu\n",
                  (fp->attached_thread == NULL)? "no": "yes", (unsigned long)fp->start_address, fp->creator_thread, fp->activation_counter, atomic64_read(&(fp->failed_activation_counter)));

        if (*off >= strnlen(string_message, 4096))
                return 0;
        size_t i = min_t(size_t, len, strnlen(string_message, 4096));
        if (copy_to_user(buf, string_message, i)) {
                return -EFAULT;
        }
        *off += i;
        return i;
}
