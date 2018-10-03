#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "fiberlib_user.h"


struct thread_info {
        unsigned long data;
};



/*void fiber_function (void * parameters)
   {
      while (1)
            printf("ghilmno\n");
   }


   void * thread_function(void *parameters)
   {
    struct thread_info *t_info = (struct thread_info *) parameters;

    printf("THREAD %lu: Starting thread_function\n", t_info->data);
    int my_fiber = ConvertThreadToFiber();
    while (SwitchToFiber(2) == -1){
            printf("THREAD %lu: Waiting for Fiber 2 to be ready\n", t_info->data);
            sleep(5);
    }

    exit(0);
   }




   struct thread_info thread_info_1 = { .data = 1 };
   struct thread_info thread_info_2 = { .data = 2 };
   int main()
   {
        printf("MAIN: Starting main...\n");
        int my_fiber = ConvertThreadToFiber();
        printf("MAIN: ConvertThreadToFiber done\n");
        printf("MAIN: spawning 4 fibers");
        int fibers[4];
        int i;
        for (i = 0; i < 4; i++){
                  fibers[i] = CreateFiber(fiber_function, 1, (void *)(i + 10));
        }
        printf("Spawning 2 more threads\n");
        pthread_t threads[2];
        pthread_create(&threads[0], NULL, thread_function, (void*) &thread_info_1);
        pthread_create(&threads[1], NULL, thread_function, (void*) &thread_info_2);
        printf("MAIN: spawned all the threads");
        while(i < 100000){
              printf("abcdef\n");
        }
        exit(0);
   }
 */

void foo (void * param)
{
        struct thread_info  *t = (struct thread_info *) param;

fiber_again:
        printf("FIBER: old thread %d\n", (int)t->data);
        SwitchToFiber(t->data);
        goto fiber_again;
        return;
}


void * thread_function(void * param){
        struct thread_info *t = (struct thread_info*) param;
        printf("THREAD %ld: Starting thread...\n", t->data);
        int k = ConvertThreadToFiber();
        printf("THREAD %ld: ConvertThreadToFiber done, fiber id %d\n", t->data, k);
        struct thread_info t_info ={ .data = k };
        int new_fiber = CreateFiber(foo, 1, (void*)&t_info);
        printf("THREAD %ld: CreateFiber done, new fiber_id %d\n", t->data, new_fiber);
again:
        SwitchToFiber(new_fiber);
        printf("THREAD %ld: again on thread\n", t->data);
        goto again;
        return NULL;
}


int main()
{
        printf("MAIN: Starting main...\n");
        int myfiber = ConvertThreadToFiber();
        printf("MAIN: ConvertThreadToFiber done, main fiber id %d\n", myfiber);
        pthread_t threads[35];
        struct thread_info t_info[35];
        unsigned long i = 0;
        for (i = 0; i < 35; i++) {
                t_info[i].data = i;
                pthread_create(&threads[i], NULL, thread_function, (void*) &t_info[i]);
        }

        for (i = 0; i < 35; i++) {
                pthread_join(threads[i], NULL);
        }
}
