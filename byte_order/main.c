#include "stdio.h"

int main(int argc, char ** argv)
{
  int a = 0x12345678;
  int *p = &a;
  char *pc = (char *)p;
  if(pc[0] == 0x78) 
  {
    printf("pc[0] = 0x%2x。\n", pc[0]);
    printf("CPU是小端。\n");
  }
  else if(pc[0] == 0x12)
  {
    printf("pc[0] = 0x%2x。\n", pc[0]);
    printf("CPU是大端。\n");
  }
  else
  {
    printf("pc[0] = 0x%2x。\n", pc[0]);
    printf("无法判断。\n");
  }
  
  return 0;
}