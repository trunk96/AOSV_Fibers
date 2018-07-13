#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/ioctl.h>
#include "fibers.h"

MODULE_LICENSE("GPL");

static char fibers[8]="fibers\n";

static int major;

#define IOCTL_SET _IOW(major, 0, char*)
#define IOCTL_GET _IOW(major, 1, char*)

static ssize_t fibers_read(struct file *f, char __user *buf,
			size_t len, loff_t *off)
{
	if (*off >= sizeof(fibers)) return 0;
	size_t i = min_t(size_t, len, sizeof(fibers));
	if (copy_to_user(buf, (fibers+*off), i)){
		return -EFAULT;
	}
	*off+=i;
	return i;

}


static long fibers_ioctl (struct file * f, unsigned int cmd, unsigned long arg)
{
	if (cmd==IOCTL_GET){
		if(copy_to_user((char*) arg, fibers, sizeof(fibers))){
			return -EFAULT;
		}
		printk(KERN_DEBUG "%s string requested: %s\n", KBUILD_MODNAME, fibers);
	}
	else if(cmd==IOCTL_SET){
		if (copy_from_user(fibers, (char*) arg, sizeof(fibers))){
			return -EFAULT;
		}
		fibers[sizeof(fibers)-1]='\0';
		printk(KERN_DEBUG "%s string changed: %s\n", KBUILD_MODNAME, fibers);
	}
	else{
		copy_to_user((char*) arg, "error!!", sizeof(fibers));
		return -EINVAL;
	}
	return 0;
}


static struct class *class_fibers;
static struct device *dev_fibers;
static struct file_operations fibers_fops = {
 .read = fibers_read,
 .unlocked_ioctl = fibers_ioctl,
 };



int fiber_init(void)
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
	printk(KERN_DEBUG "%s IOCTL_GET command is %ld\n", KBUILD_MODNAME, IOCTL_GET);
	printk(KERN_DEBUG "%s IOCTL_SET command is %ld\n", KBUILD_MODNAME, IOCTL_SET);
	return 0;
err:
	class_destroy(class_fibers);
err2:
	unregister_chrdev(major, "fibers");
	return PTR_ERR(ptr_err);
}

void fiber_cleanup(void)
{
	device_destroy(class_fibers, MKDEV(major, 0));
	class_destroy(class_fibers);
	return unregister_chrdev(major, "fibers");
}


module_init(fiber_init);
module_exit(fiber_cleanup);
