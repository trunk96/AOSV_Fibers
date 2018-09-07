#define IOCTL_CONVERT_THREAD_TO_FIBER _IO(major, 0)
#define IOCTL_CREATE_FIBER _IOW(major, 1, void*)
#define IOCTL_SWITCH_TO_FIBER _IOW(major, 2, void*)
#define IOCTL_FLS_ALLOC _IO(major, 3)
#define IOCTL_FLS_FREE _IOW(major, 4, void*)
#define IOCTL_FLS_GETVALUE _IOWR(major, 5, void*) //we use void* since ve have to write the index to the kernel
                                                  //and we have to read the result into an user buffer
#define IOCTL_FLS_SETVALUE _IOW(major, 6, void*)  //we use void* to pack both the index and the buffer to be passed to the kernel


#define MESSAGE_MAX_LEN 256


extern long major;
void publish_ioctl_message(void);
static long fibers_ioctl(struct file *, unsigned int, unsigned long);
