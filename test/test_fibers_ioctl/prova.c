#include <stdio.h>
#include <fcntl.h>
#include "prova.h"
#include <stdlib.h>
#include <unistd.h>



int main()
{
  int fd=open("/dev/fibers", O_RDONLY);
  char buf[128];
  long ret=read(fd, buf, sizeof(buf));
  char *major;
  ret = strtol(buf, &major, 10);
  if (ret < 0)
    exit(-1);
  ret=ioctl(fd, IOCTL_CONVERT_THREAD_TO_FIBER, 0);
  printf("ret value is %ld\n", ret);
}
