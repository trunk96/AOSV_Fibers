#include "device.h"


long major=0;
static struct class *class_fibers;
static struct device *dev_fibers;

static ssize_t fibers_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
				size_t i;
				if (*off >= strnlen(string_message, MESSAGE_MAX_LEN))
				        return 0;
				i = min_t(size_t, len, strnlen(string_message, MESSAGE_MAX_LEN));
				if (copy_to_user(buf, (string_message+*off), i)) {
				        return -EFAULT;
				}
				*off += i;
				return i;

}

int fiber_open(struct inode *inode, struct file *file)
{
				if (!try_module_get(THIS_MODULE)){
								return -1;
				}
				return 0;
}

int fiber_close(struct inode *inode, struct file *file)
{
				process_cleanup();
				module_put(THIS_MODULE);
				return 0;
}


static struct file_operations fibers_fops = {
        .read = fibers_read,
        //.unlocked_ioctl = ioctl_function    ioctl_function is not constant, so we have to add it later
				.open = fiber_open,
				.release = fiber_close,
};

static char *fiber_user_devnode(struct device *dev, umode_t *mode)
{
        if (mode)
                *mode = 0666;
        return kasprintf(GFP_KERNEL, "%s", dev_name(dev));
}


int register_fiber_device(void)
{
        void *ptr_err;
        fibers_fops.unlocked_ioctl = ioctl_function;
        if ((major = register_chrdev(0, "fibers", &fibers_fops)) < 0){
                printk(KERN_DEBUG "%s: Cannot get a valid major number for /dev/fibers\n", KBUILD_MODNAME);
                return major;
        }

        class_fibers = class_create(THIS_MODULE, "fibers");
        if (IS_ERR(ptr_err = class_fibers)){
                printk(KERN_DEBUG "%s: Cannot create a device class for /dev/fibers\n", KBUILD_MODNAME);
                goto err2;
        }

        class_fibers->devnode = fiber_user_devnode;

        dev_fibers = device_create(class_fibers, NULL, MKDEV(major, 0), NULL, "fibers");
        if (IS_ERR(ptr_err = dev_fibers)){
                printk(KERN_DEBUG "%s: Cannot create /dev/fibers\n", KBUILD_MODNAME);
                goto err;
        }

        printk(KERN_DEBUG "%s: Device successfully registered in /dev/fibers with major number %ld\n", KBUILD_MODNAME, major);

        //publish ioctl cmds here (so userspace library can read ioctl cmds)
        publish_message();
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
