#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/string.h>
#include <linux/pid.h>
#include "fibers.h"
#include "ioctl.h"


char string_message[MESSAGE_MAX_LEN] = "";

void publish_ioctl_message()
{
        snprintf(string_message, MESSAGE_MAX_LEN, "%ld\n%ld\n%ld\n%ld\n%ld\n%ld\n%ld\0",
                 IOCTL_CONVERT_THREAD_TO_FIBER,
                 IOCTL_CREATE_FIBER,
                 IOCTL_SWITCH_TO_FIBER,
                 IOCTL_FLS_ALLOC,
                 IOCTL_FLS_FREE,
                 IOCTL_FLS_GETVALUE,
                 IOCTL_FLS_SETVALUE);
}

spinlock_t big_lock = __SPIN_LOCK_UNLOCKED(big_lock);

static long fibers_ioctl(struct file * f, unsigned int cmd, unsigned long arg)
{
        unsigned long flags;
        spin_lock_irqsave(&big_lock, flags);
        struct task_struct *current_thread = current;
        pid_t thread_id=current->pid;

        if (cmd == IOCTL_CONVERT_THREAD_TO_FIBER) {
                //arg has no sense in this context
                long ret = (long) do_ConvertThreadToFiber(thread_id);
                spin_unlock_irqrestore(&big_lock, flags);
                return ret;
        }
        else if (cmd == IOCTL_CREATE_FIBER) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        spin_unlock_irqrestore(&big_lock, flags);
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        spin_unlock_irqrestore(&big_lock, flags);
                        return -EFAULT;
                }
                //printk(KERN_DEBUG "%s fa.stackpointer is %ld, fa.start_function_address is %ld\n", KBUILD_MODNAME, fa.stack_pointer, (long)fa.start_function_address);
                long ret = (long) do_CreateFiber(fa.stack_pointer, fa.stack_size, fa.start_function_address, fa.start_function_arguments, thread_id);
                spin_unlock_irqrestore(&big_lock, flags);
                return ret;
        }
        else if (cmd == IOCTL_SWITCH_TO_FIBER) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        spin_unlock_irqrestore(&big_lock, flags);
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        spin_unlock_irqrestore(&big_lock, flags);
                        return -EFAULT;
                }
                long ret = do_SwitchToFiber(fa.fiber_id, thread_id);
                spin_unlock_irqrestore(&big_lock, flags);
                return ret;
        }
        else if (cmd == IOCTL_FLS_ALLOC) {
                long ret = (long) do_FlsAlloc(thread_id);
                spin_unlock_irqrestore(&big_lock, flags);
                return ret;
        }
        else if (cmd == IOCTL_FLS_FREE) {
                printk(KERN_DEBUG "%s: IOCTL handler for FlsFree()\n", KBUILD_MODNAME);
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        spin_unlock_irqrestore(&big_lock, flags);
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        spin_unlock_irqrestore(&big_lock, flags);
                        return -EFAULT;
                }
                long ret = (long) do_FlsFree(fa.index, thread_id);
                spin_unlock_irqrestore(&big_lock, flags);
                return ret;
        }
        else if (cmd == IOCTL_FLS_GETVALUE) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        spin_unlock_irqrestore(&big_lock, flags);
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        spin_unlock_irqrestore(&big_lock, flags);
                        return -EFAULT;
                }

                long ret = (long) do_FlsGetValue(fa.index, thread_id);
                printk(KERN_DEBUG "%s: kernel mode returning value %lu\n", KBUILD_MODNAME, ret);
                spin_unlock_irqrestore(&big_lock, flags);
                return ret;
        }
        else if (cmd == IOCTL_FLS_SETVALUE) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        spin_unlock_irqrestore(&big_lock, flags);
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        spin_unlock_irqrestore(&big_lock, flags);
                        return -EFAULT;
                }
                do_FlsSetValue(fa.index, fa.buffer, thread_id);
                spin_unlock_irqrestore(&big_lock, flags);
                return 0;
        }
        else {
                spin_unlock_irqrestore(&big_lock, flags);
                return -EINVAL;
        }

}



long (*ioctl_function)(struct file *, unsigned int, unsigned long) = fibers_ioctl;
void (*publish_message)(void) = publish_ioctl_message;
