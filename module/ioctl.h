#define IOCTL_CONVERT_THREAD_TO_FIBER _IO(major, 0)
#define IOCTL_CREATE_FIBER _IO(major, 1)
#define IOCTL_SWITCH_TO_FIBER _IO(major, 2)
#define IOCTL_FLS_ALLOC _IO(major, 3)
#define IOCTL_FLS_FREE _IO(major, 4)
#define IOCTL_FLS_GETVALUE _IO(major, 5)
#define IOCTL_FLS_SETVALUE _IO(major, 6)

#define MESSAGE_MAX_LEN 256


extern long major;
void publish_ioctl_message(void);
static long fibers_ioctl(struct file *, unsigned int, unsigned long);
