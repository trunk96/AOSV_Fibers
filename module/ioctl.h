#define IOCTL_CONVERT_THREAD_TO_FIBER _IO(major, 0)
//#define IOCTL_CREATE_FIBER _IOW(major, 1, void*)
#define IOCTL_CREATE_FIBER _IO(major, 1)
//#define IOCTL_SWITCH_TO_FIBER _IOW(major, 2, void*)
#define IOCTL_SWITCH_TO_FIBER _IO(major, 2)
#define IOCTL_FLS_ALLOC _IO(major, 3)
#define IOCTL_FLS_FREE _IO(major, 4)
#define IOCTL_FLS_GETVALUE _IO(major, 5) //we use void* since ve have to write the index to the kernel
                                                  //and we have to read the result into an user buffer
#define IOCTL_FLS_SETVALUE _IO(major, 6)  //we use void* to pack both the index and the buffer to be passed to the kernel


#define MESSAGE_MAX_LEN 256


extern long major;
void publish_ioctl_message(void);
static long fibers_ioctl(struct file *, unsigned int, unsigned long);
