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
        long counter = 0;
        //double x = 0.0;
        while(1) {
                if (counter % 10000000 == 0){
                      //printf("ciao, %f\n", x);
                      printf("ciao\n");
                      break;
                      //x+=0.5;
                }
                counter++;
        }
        SwitchToFiber(1);
        counter = 0;
        double x = 0.0;
        while(1) {
                if (counter % 10000000 == 0){
                      //printf("ciao, %f\n", x);
                      //printf("ciao\n");
                      x+=0.5;
                }
                if (x < 0){
                  break;
                }
                counter++;
        }


        exit(0);
}

int main()
{
        printf("Starting main...\n");
        int my_fiber = ConvertThreadToFiber();
        char c = 'c';
        int new_fiber = CreateFiber(function, 6, &c);
        SwitchToFiber(new_fiber);
        long counter = 0;
        double x = 0.0;
        while(1) {
                if (counter % 10000000 == 0){
                      printf("bella, %f\n", x);
                      //printf("ciao\n");
                      x+=0.5;
                      break;
                }
                counter++;
        }
        SwitchToFiber(new_fiber);
        exit(0);
}
