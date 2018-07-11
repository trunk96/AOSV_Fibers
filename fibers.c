#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/cdev.h>


MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("Emanuele De Santis <desantis.1664777@studenti.uniroma1.it");
MODULE_AUTHOR("Maria Ludovica Costagliola <costagliola.1657716@studenti.uniroma1.it");
MODULE_VERSION("0.1");

MODULE_PARM_DESC(content, "Fibers implementation for Linux kernel");


static char a[16]="Hello world!!!!";
static ssize_t a_lenght=sizeof(a);

static ssize_t fibers_dev_read(struct file *file_ptr, char *usr_buffer, size_t count, loff_t *position)
{
	printk(KERN_DEBUG "%s starting reading from string\n", KBUILD_MODNAME);
	if (*position >= a_lenght){
		return 0;
	}
	if (*position + count >= a_lenght){
		count = a_lenght - *position;
	}
	if( copy_to_user(usr_buffer, a + *position, count) != 0 )
        return -EFAULT;    
    /* Move reading position */
    *position += count;
    return count;
}



static struct file_operations fibers_fops =
{
	.owner = THIS_MODULE,	
	.read = fibers_dev_read,
};

static int major=0;
static dev_t fiber_dev;
static struct class *fiber_class;
static struct cdev *fiber_cdev;
static struct device *fiber_device;

static int fibers_init(void)
{
	int ret;
	
	/*if ((ret = register_chrdev(major, "fibers", &fibers_fops)) < 0){
		printk(KERN_EMERG "%s cannot allocate a valid major number for the device, exiting...\n", KBUILD_MODNAME);
		return ret;
	}
	major=ret;
	printk(KERN_DEBUG "%s successfully allocated with major number %d\n", KBUILD_MODNAME, major);*/
	
	if ((ret = alloc_chrdev_region(&fiber_dev, 0, 1, "fibers")) < 0){
		printk(KERN_EMERG "%s problem 1\n", KBUILD_MODNAME);
		return ret;
	}
	fiber_class = class_create(THIS_MODULE, "fibers");
	cdev_init(fiber_cdev, &fibers_fops);
	if ((ret = cdev_add(fiber_cdev, fiber_dev, 0)) < 0){
		printk(KERN_EMERG "%s problem 2\n", KBUILD_MODNAME);
		return ret;
	}
	
	fiber_device=device_create(fiber_class, NULL, fiber_dev, "fiber", NULL);
	
	return 0;
}


static void fibers_exit(void)
{
	//unregister_chrdev(major, "fibers");
	
	device_destroy(fiber_class, fiber_dev);
	printk(KERN_DEBUG "%s device deallocated successfully\n", KBUILD_MODNAME);
}




module_init(fibers_init);
module_exit(fibers_exit);
