#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>

MODULE_LICENSE("GPL");

#define foo "fibers"
#define foolen 7

static ssize_t read_foo(struct file *f, char __user *buf,
			size_t len, loff_t *off)
{
	size_t i = min_t(size_t, len, foolen);
	return copy_to_user(buf, foo "\n", i) ? -EFAULT : i;
}

static int major;
static struct class *class_foo;
static struct device *dev_foo;
static struct file_operations f = { .read = read_foo };

int init_module(void)
{
	void *ptr_err;
	if ((major = register_chrdev(0, foo, &f)) < 0)
		return major;

	class_foo = class_create(THIS_MODULE, foo);
	if (IS_ERR(ptr_err = class_foo))
		goto err2;

	dev_foo = device_create(class_foo, NULL, MKDEV(major, 0), NULL, foo);
	if (IS_ERR(ptr_err = dev_foo))
		goto err;

	/* struct kobject *play_with_this = &dev_foo->kobj; */

	return 0;
err:
	class_destroy(class_foo);
err2:
	unregister_chrdev(major, foo);
	return PTR_ERR(ptr_err);
}

void cleanup_module(void)
{
	device_destroy(class_foo, MKDEV(major, 0));
	class_destroy(class_foo);
	return unregister_chrdev(major, foo);
}
