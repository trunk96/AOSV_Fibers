int register_fiber_device(void);
static ssize_t fibers_read(struct file *, char*, size_t, loff_t *);
void unregister_fiber_device(void);

#define MESSAGE_MAX_LEN 256
extern char string_message[MESSAGE_MAX_LEN];
extern long (*ioctl_function)(struct file *, unsigned int, unsigned long);
extern void (*publish_message)(void);
