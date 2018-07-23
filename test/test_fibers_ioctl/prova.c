#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>


typedef enum IOCTL_TYPE{
  IOCTL_CONVERT_THREAD_TO_FIBER=0,
  IOCTL_CREATE_FIBER,
  IOCTL_SWITCH_TO_FIBER,
  IOCTL_FLS_ALLOC,
  IOCTL_FLS_FREE,
  IOCTL_FLS_GETVALUE,
  IOCTL_FLS_SETVALUE
} ioctl_type_t;


int main()
{
  int fd = open("/dev/fibers", O_RDONLY);
  char buf[256];
  long ret = read(fd, buf, sizeof(buf));
  char *token;
  char *ptr;
  const char delimiter[2]="\n";
  //printf("%s\n", buf);

  token = strtok(buf, delimiter);
  long ioctl_numbers[7]={0};
  int i = 0;

  while(token != NULL){

    ioctl_numbers[i] = strtol(token, &ptr, 10);
    token = strtok(NULL, delimiter);
    i++;
  }

  for (i = 0; i < 7; i++){
    printf("%ld\n", ioctl_numbers[i]);
  }
  ret = ioctl(fd, ioctl_numbers[IOCTL_FLS_ALLOC], 0);
  printf("ret value is %ld\n", ret);
}
