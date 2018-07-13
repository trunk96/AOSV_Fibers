#include <sys/ioctl.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd=open("/dev/fibers", O_RDONLY);
	char msg[8]="ciao";
	int ret=ioctl(fd, 1074328321, msg);
	printf("%d\n", ret);
	printf("msg received is %s\n", msg);
	char msg_new[8]="ciao!!\n";
	ret=ioctl(fd, 1074328320, msg_new);
	printf("%d\n", ret);
	printf("msg sent is %s\n", msg_new);
}
