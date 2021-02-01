#include "stdio.h"

#define ABS(a,b) ((a)>(b)?(a)-(b):(b)-(a))

int main()
{
    int a = 10;
    void *p;
    p = &a;
    printf("1. int a 的地址是：0x%X \n", p);
    printf("2. 指针p占用%d个字节\n", sizeof(p));

    char b = 'b';
    void *q;
    q = &b;
    printf("3. char b 的地址是：0x%X \n", q);
    printf("4. 指针q占用%d个字节\n", sizeof(q));

    int c = 5;
    int d = 6;
    printf("5. c - d 的绝对值是： %d \n", ABS(c,d));
    return 0;
}