#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/ioctl.h>
#include <linux/string.h>
#include "device.h"

#define MAJOR_MAX_LEN 256

static long major;
static struct class *class_fibers;
static struct device *dev_fibers;
static char string_major[MAJOR_MAX_LEN]="";


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
	/*if (cmd == IOCTL_GET){
		if(copy_to_user((char*) arg, fibers, sizeof(fibers))){
			return -EFAULT;
		}
		printk(KERN_DEBUG "%s string requested: %s\n", KBUILD_MODNAME, fibers);
	}
	else if(cmd == IOCTL_SET){
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
	return 0;*/
  return -EINVAL;
}


static ssize_t fibers_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
	if (*off >= strnlen(string_major, MAJOR_MAX_LEN)) return 0;
	size_t i = min_t(size_t, len, strnlen(string_major, MAJOR_MAX_LEN));
	if (copy_to_user(buf, (string_major+*off), i)){
		return -EFAULT;
	}
	*off += i;
	return i;

}
