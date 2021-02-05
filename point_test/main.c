#include "stdio.h"

typedef void *PVOID;//typedef 定义void *指针类型

int main(int argc, char** argv)
{
  PVOID p;
  int a = 100;
  p = &a;//测试指针类型PVOID是否可用
  printf("1. p = 0x%X \n", p);
  return 0;
}