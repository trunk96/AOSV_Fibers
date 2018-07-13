#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/ioctl.h>
#include <linux/string.h>
#include "device.h"
#include "fibers.h"

#define MAJOR_MAX_LEN 256

static long major;
static struct class *class_fibers;
static struct device *dev_fibers;
static char string_major[MAJOR_MAX_LEN] = "";


static struct file_operations fibers_fops = {
        .read = fibers_read,
        .unlocked_ioctl = fibers_ioctl,
};


int register_fiber_device(void)
{
        void *ptr_err;
        if ((major = register_chrdev(0, "fibers", &fibers_fops)) < 0)
                return major;

        class_fibers = class_create(THIS_MODULE, "fibers");
        if (IS_ERR(ptr_err = class_fibers))
                goto err2;

        dev_fibers = device_create(class_fibers, NULL, MKDEV(major, 0), NULL, "fibers");
        if (IS_ERR(ptr_err = dev_fibers))
                goto err;
        printk(KERN_DEBUG "%s Device successfully registered in /dev/fibers with major number %ld\n", KBUILD_MODNAME, major);
        snprintf(string_major, MAJOR_MAX_LEN, "%ld", major);
        return 0;

err:
        class_destroy(class_fibers);
err2:
        unregister_chrdev(major, "fibers");
        return PTR_ERR(ptr_err);
}

void unregister_fiber_device(void)
{
        device_destroy(class_fibers, MKDEV(major, 0));
        class_destroy(class_fibers);
        return unregister_chrdev(major, "fibers");
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
                return (long) do_SwitchToFiber(fa.fiber_address);
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
                return (long) do_FlsFree(fa.index);
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
                return (long) do_FlsSetValue(fa.index, fa.value);
        }
        else {
                return -EINVAL;
        }
        return 0;
}


static ssize_t fibers_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
        if (*off >= strnlen(string_major, MAJOR_MAX_LEN))
                return 0;
        size_t i = min_t(size_t, len, strnlen(string_major, MAJOR_MAX_LEN));
        if (copy_to_user(buf, (string_major+*off), i)) {
                return -EFAULT;
        }
        *off += i;
        return i;

}
