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


const int tab64[64] = {
    63,  0, 58,  1, 59, 47, 53,  2,
    60, 39, 48, 27, 54, 33, 42,  3,
    61, 51, 37, 40, 49, 18, 28, 20,
    55, 30, 34, 11, 43, 14, 22,  4,
    62, 57, 46, 52, 38, 26, 32, 41,
    50, 36, 17, 19, 29, 10, 13, 21,
    56, 45, 25, 31, 35, 16,  9, 12,
    44, 24, 15,  8, 23,  7,  6,  5};

int log2_64 (unsigned long value)
{
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    value |= value >> 32;
    return tab64[((unsigned long)((value - (value >> 1))*0x07EDD5E59A4E28C2)) >> 58];
}


void myfunction(void* parameters){
  long counter = 0;
  char * character = (char *) parameters;
  struct fiber_arguments fa2 = {
    .fiber_id = 1,
    .alloc_size = 8,
  };
  long index = ioctl(fd, ioctl_numbers[IOCTL_FLS_ALLOC], &fa2);
  index = ioctl(fd, ioctl_numbers[IOCTL_FLS_ALLOC], &fa2);
  fa2.index = index;
  fa2.buffer = (unsigned long) malloc(8*sizeof(char));
  *((unsigned long *)fa2.buffer) = 15;
  long r = ioctl(fd, ioctl_numbers[IOCTL_FLS_SETVALUE], &fa2);
  free((unsigned long*)fa2.buffer);
  fa2.buffer = (unsigned long) malloc(sizeof(long));
  r = ioctl(fd, ioctl_numbers[IOCTL_FLS_GETVALUE], &fa2);
  printf("The number is %ld\n", *((unsigned long *)fa2.buffer));
  index = ioctl(fd, ioctl_numbers[IOCTL_FLS_FREE], &fa2);
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
  exit(0);
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
  exit(0);
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
  printf("Log2 of 3 is %d\n", log2_64(3));
}
