#include "fiberlib_user.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void function (void* parameters)
{
        printf("Starting function...\n");
        long index = FlsAlloc();
        long long l1 = 123456;
        FlsSetValue(l1, index);
        long long l2;
        l2 = FlsGetValue(index);
        /*printf("Parameters is %c and value is %c\n", *((char*)parameters), b);
        FlsFree(index);*/
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
        float x __attribute__ ((aligned (16))) = 0.0;
        while(1) {
                if (counter % 10000000 == 0){
                      //printf("ciao, %f\n", x);
                      //printf("ciao\n");
                      x+=0.5;
                }
                if (x > 1){
                  break;
                }
                counter++;
        }
        SwitchToFiber(1);
        x += 0.6;
        if (x > 1.5){
          printf("bellaaaaaaaaaaa\n");
        }
        for (counter = 0; counter < 10000000; counter ++){
          printf("abcdefg\n");
        }
        /*while(1) {
                if (counter % 10000000 == 0){
                      //printf("ciao, %f\n", x);
                      //printf("ciao\n");
                      x+=0.6;
                }
                if (x > 1.5){
                  break;
                }
                counter++;
        }*/
        SwitchToFiber(1);
        exit(0);
}

int main()
{
        printf("Starting main...\n");
        int my_fiber = ConvertThreadToFiber();
        printf("ConvertThreadToFiber done\n");
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
        for (counter = 0; counter < 10000000; counter ++){
          printf("hilmnopq\n");
        }
        SwitchToFiber(new_fiber);
        exit(0);
}
