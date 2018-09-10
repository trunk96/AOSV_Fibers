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

static long fibers_ioctl(struct file * f, unsigned int cmd, unsigned long arg)
{
        struct task_struct *current_thread = current;
        pid_t thread_id=current->pid;

        if (cmd == IOCTL_CONVERT_THREAD_TO_FIBER) {
                //arg has no sense in this context
                return do_ConvertThreadToFiber(thread_id);
        }
        else if (cmd == IOCTL_CREATE_FIBER) {
                struct fiber_arguments fa;
                /*if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                   }
                   if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                   }*/
                return (long) do_CreateFiber(fa.stack_size, fa.start_function_address, fa.start_function_arguments, thread_id);
        }
        else if (cmd == IOCTL_SWITCH_TO_FIBER) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                return do_SwitchToFiber(fa.fiber_address, thread_id);
        }
        else if (cmd == IOCTL_FLS_ALLOC) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                if (fa.alloc_size < 0)
                        return -EFAULT;
                return do_FlsAlloc(fa.alloc_size, thread_id);
        }
        else if (cmd == IOCTL_FLS_FREE) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                return do_FlsFree(fa.index, thread_id);
        }
        else if (cmd == IOCTL_FLS_GETVALUE) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                return (long) do_FlsGetValue(fa.index, thread_id);
        }
        else if (cmd == IOCTL_FLS_SETVALUE) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                return do_FlsSetValue(fa.index, fa.value, thread_id);
        }
        else {
                return -EINVAL;
        }
}



long (*ioctl_function)(struct file *, unsigned int, unsigned long) = fibers_ioctl;
void (*publish_message)(void) = publish_ioctl_message;
