#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include "prova.h"


typedef enum IOCTL_TYPE{
  IOCTL_CONVERT_THREAD_TO_FIBER=0,
  IOCTL_CREATE_FIBER,
  IOCTL_SWITCH_TO_FIBER,
  IOCTL_FLS_ALLOC,
  IOCTL_FLS_FREE,
  IOCTL_FLS_GETVALUE,
  IOCTL_FLS_SETVALUE
} ioctl_type_t;

int fd;
long ioctl_numbers[7]={0};

void myfunction(void* parameters){
  long counter = 0;
  char * character = (char *) parameters;
  struct fiber_arguments fa2 = {
    .fiber_id = 1,
  };
  while(1){
    printf("Ora %c, %ld\n", *character, counter++);
    if (counter == 10){
      long ret = ioctl(fd, ioctl_numbers[IOCTL_SWITCH_TO_FIBER], &fa2);
      if (ret == -1){
        printf("FBIDBVCIDBVCOSDNOVNADPNVOADNVOADNVONDOVNAONVOADNVONADOVNADONVOADN\n");
        break;
      }
    }
    //printf("character is %c, %ld\n", *character, counter++);
  }
  return;
}




void myfunction2 (void* parameters){
  long counter = 0;
  char * character = (char *) parameters;
  struct fiber_arguments fa2 = {
    .stack_size = 1,
    .start_function_address = myfunction,
    .start_function_arguments = (void*)(character),
  };
  fa2.stack_pointer = malloc(4096*2*sizeof(char));
  pid_t addr = (unsigned long) ioctl(fd, ioctl_numbers[IOCTL_CREATE_FIBER], &fa2);
  fa2.fiber_id = addr;
  while(1){
    printf("%c, %ld\n", *character, counter++);
    if (counter == 10){
      long ret = ioctl(fd, ioctl_numbers[IOCTL_SWITCH_TO_FIBER], &fa2);
      if (ret == -1){
        printf("FBIDBVCIDBVCOSDNOVNADPNVOADNVOADNVONDOVNAONVOADNVONADOVNADONVOADN\n");
        break;
      }
    }
  }
}


int main()
{
  fd = open("/dev/fibers", O_RDONLY);
  char buf[256];
  long ret = read(fd, buf, sizeof(buf));
  char *token;
  char *ptr;
  const char delimiter[2]="\n";
  //printf("%s\n", buf);

  token = strtok(buf, delimiter);
  int i = 0;

  while(token != NULL){

    ioctl_numbers[i] = strtol(token, &ptr, 10);
    token = strtok(NULL, delimiter);
    i++;
  }

  for (i = 0; i < 7; i++){
    printf("%ld\n", ioctl_numbers[i]);
  }

  char ciao = 'd';
  struct fiber_arguments fa = {
    .stack_size = 1,
    .start_function_address = myfunction2,
    .start_function_arguments = (void*)(&ciao),
  };
  ret = ioctl(fd, ioctl_numbers[IOCTL_CONVERT_THREAD_TO_FIBER], 0);
  printf("Thread converted to fiber with fiber_id %lu\n", ret);

  fa.stack_pointer = malloc(4096*2*sizeof(char));
  printf("stack_pointer is %lu\n", (unsigned long) fa.stack_pointer);
  pid_t addr = (unsigned long) ioctl(fd, ioctl_numbers[IOCTL_CREATE_FIBER], &fa);
  fa.fiber_id = addr;
  printf("New fiber created with id %d, PID is %d\n myfunction is in address %lu\n", addr, getpid(), (unsigned long)myfunction);

  ret = ioctl(fd, ioctl_numbers[IOCTL_SWITCH_TO_FIBER], &fa);
  //printf("ret value is %ld, PID is %d\n myfunction is in address %ld\n", ret, getpid(), (long)myfunction);

  printf("End of the story\n");
}
