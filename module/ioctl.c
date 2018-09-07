#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/string.h>
#include "fibers.h"
#include "ioctl.h"


MODULE_LICENSE("GPL");


#define IOCTL_CONVERT_THREAD_TO_FIBER _IO(major, 0)
#define IOCTL_CREATE_FIBER _IOW(major, 1, void*)
#define IOCTL_SWITCH_TO_FIBER _IOW(major, 2, void*)
#define IOCTL_FLS_ALLOC _IO(major, 3)
#define IOCTL_FLS_FREE _IOW(major, 4, void*)
#define IOCTL_FLS_GETVALUE _IOWR(major, 5, void*) //we use void* since ve have to write the index to the kernel
                                                  //and we have to read the result into an user buffer
#define IOCTL_FLS_SETVALUE _IOW(major, 6, void*)  //we use void* to pack both the index and the buffer to be passed to the kernel


#define MESSAGE_MAX_LEN 256

char string_message[MESSAGE_MAX_LEN] = "";



void publish_ioctl_message ()
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

static long fibers_ioctl (struct file * f, unsigned int cmd, unsigned long arg)
{
        if (cmd == IOCTL_CONVERT_THREAD_TO_FIBER) {
                //arg has no sense in this context
                return do_ConvertThreadToFiber();
        }
        else if (cmd == IOCTL_CREATE_FIBER) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                return (long) do_CreateFiber(fa.stack_size, fa.start_function_address, fa.start_function_arguments);
        }
        else if (cmd == IOCTL_SWITCH_TO_FIBER) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                return do_SwitchToFiber(fa.fiber_address);
        }
        else if (cmd == IOCTL_FLS_ALLOC) {
                //arg has no sense in this context
                return do_FlsAlloc();
        }
        else if (cmd == IOCTL_FLS_FREE) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                return do_FlsFree(fa.index);
        }
        else if (cmd == IOCTL_FLS_GETVALUE) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                return (long) do_FlsGetValue(fa.index);
        }
        else if (cmd == IOCTL_FLS_SETVALUE) {
                struct fiber_arguments fa;
                if (!access_ok(VERIFY_READ, arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                if (copy_from_user(&fa, (void*)arg, sizeof(struct fiber_arguments))) {
                        return -EFAULT;
                }
                return do_FlsSetValue(fa.index, fa.value);
        }
        else {
                return -EINVAL;
        }
}



long (*ioctl_function)(struct file *, unsigned int, unsigned long) = fibers_ioctl;
void (*publish_message)(void) = publish_ioctl_message;
