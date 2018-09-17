#include "fiberlib_user.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void function (void* parameters)
{
    printf("Starting function...\n");
    unsigned long index = FlsAlloc(sizeof(long));
    char a = 'a';
    FlsSetValue(&a, index);
    char b;
    FlsGetValue(&b, index);
    printf("Parameters is %c and value is %c\n", *((char*)parameters), b);
    FlsFree(index);
    exit(0);
}

int main()
{
  printf("Starting main...\n");
  int my_fiber = ConvertThreadToFiber();
  char c = 'c';
  int new_fiber = CreateFiber(function, 6, &c);
  SwitchToFiber(new_fiber);
  exit(0);
}
