#include "stdio.h"

#define LWIP_MEMPOOL(name,num,size,desc) memp_##name,
#define CONNECT(a,b) a ## b
#define CONNECTS(a,b) a ## b

int main()
{
    int a = CONNECT(123,456);
    printf("1. a = %d \n", a);
    char *c = CONNECTS("abc", "def");
    printf("2. c = %s \n", c);
    return 0;
}