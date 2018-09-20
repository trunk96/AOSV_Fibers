#include <unistd.h>

typedef void (*user_function_t)(void* param);

void* ConvertThreadToFiber();
void* CreateFiber(void (*entry_point)(void *), unsigned long, void *);
void SwitchToFiber(void*);
long FlsAlloc(void);
long FlsFree(unsigned long);
long long FlsGetValue(unsigned long);
void FlsSetValue(long long, unsigned long);
