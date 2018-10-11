#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/string.h>

#define MESSAGE_MAX_LEN 256

int register_fiber_device(void);
void unregister_fiber_device(void);


extern char string_message[MESSAGE_MAX_LEN];
extern long (*ioctl_function)(struct file *, unsigned int, unsigned long);
extern void (*publish_message)(void);
extern int process_cleanup(void);
