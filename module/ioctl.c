#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/string.h>
#include <linux/pid.h>
#include "fibers.h"
#include "ioctl.h"


char string_message[MESSAGE_MAX_LEN] = "";

void publish_ioctl_message()
{
        snprintf(string_message, MESSAGE_MAX_LEN, "%ld\n%ld\n%ld\n%ld\n%ld\n%ld\n%ld\n",
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
        pid_t thread_id=current->pid;

        if (cmd == IOCTL_CONVERT_THREAD_TO_FIBER) {
                //arg has no sense in this context
                long ret = (long) do_ConvertThreadToFiber(thread_id);
                return ret;
        }
        else if (cmd == IOCTL_CREATE_FIBER) {
                struct fiber_arguments fa;
                long ret;

                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        printk(KERN_DEBUG "%s: Bad pointer to IOCTL\n", KBUILD_MODNAME);
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        printk(KERN_DEBUG "%s: Cannot copy user arguments of IOCTL\n", KBUILD_MODNAME);
                        return -EFAULT;
                }
                ret = (long) do_CreateFiber(fa.stack_pointer, fa.stack_size, fa.start_function_address, fa.start_function_arguments, thread_id);
                return ret;
        }
        else if (cmd == IOCTL_SWITCH_TO_FIBER) {
                long ret;
                struct fiber_arguments fa;

                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        printk(KERN_DEBUG "%s: Bad pointer to IOCTL\n", KBUILD_MODNAME);
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        printk(KERN_DEBUG "%s: Cannot copy user arguments of IOCTL\n", KBUILD_MODNAME);
                        return -EFAULT;
                }

                ret = do_SwitchToFiber(fa.fiber_id, thread_id);
                return ret;
        }
        else if (cmd == IOCTL_FLS_ALLOC) {
                //arg has no sense in this context
                long ret = (long) do_FlsAlloc(thread_id);
                return ret;
        }
        else if (cmd == IOCTL_FLS_FREE) {
                struct fiber_arguments fa;
                long ret;

                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        printk(KERN_DEBUG "%s: Bad pointer to IOCTL\n", KBUILD_MODNAME);
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        printk(KERN_DEBUG "%s: Cannot copy user arguments of IOCTL\n", KBUILD_MODNAME);
                        return -EFAULT;
                }
                ret = (long) do_FlsFree(fa.index, thread_id);
                return ret;
        }
        else if (cmd == IOCTL_FLS_GETVALUE) {
                struct fiber_arguments fa;
                long long ret;

                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        printk(KERN_DEBUG "%s: Bad pointer to IOCTL\n", KBUILD_MODNAME);
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        printk(KERN_DEBUG "%s: Cannot copy user arguments of IOCTL\n", KBUILD_MODNAME);
                        return -EFAULT;
                }

                ret = do_FlsGetValue(fa.index, thread_id);
                if (copy_to_user((void*)fa.buffer, &ret, sizeof(long long))){
                        return -EFAULT;
                }
                return 0;
        }
        else if (cmd == IOCTL_FLS_SETVALUE) {

                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        printk(KERN_DEBUG "%s: Bad pointer to IOCTL\n", KBUILD_MODNAME);
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        printk(KERN_DEBUG "%s: Cannot copy user arguments of IOCTL\n", KBUILD_MODNAME);
                        return -EFAULT;
                }
                do_FlsSetValue(fa.index, fa.buffer, thread_id);
                return 0;
        }
        else {
                printk(KERN_DEBUG "%s: Bad IOCTL command\n", KBUILD_MODNAME);
                return -EINVAL;
        }

}


long (*ioctl_function)(struct file *, unsigned int, unsigned long) = fibers_ioctl;
void (*publish_message)(void) = publish_ioctl_message;
