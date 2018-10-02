#include <unistd.h>
#include <stdbool.h>

typedef void (*user_function_t)(void* param);


pid_t ConvertThreadToFiber();
pid_t CreateFiber(user_function_t, unsigned long, void *);
long SwitchToFiber(pid_t);
long FlsAlloc();
bool FlsFree(long);
long long FlsGetValue(long);
void FlsSetValue(long long, long);
