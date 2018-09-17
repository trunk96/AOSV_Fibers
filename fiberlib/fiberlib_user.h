#include <unistd.h>

typedef void (*user_function_t)(void* param);

pid_t ConvertThreadToFiber();
pid_t CreateFiber(user_function_t, unsigned long, void *);
long SwitchToFiber(pid_t);
long FlsAlloc(unsigned long);
long FlsFree(unsigned long);
long FlsGetValue(void *, unsigned long);
long FlsSetValue(void *, unsigned long);
