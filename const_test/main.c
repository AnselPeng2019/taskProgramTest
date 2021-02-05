#include "stdio.h"

int var = 10;
const int *pvar = &var;

int main()
{
  printf("1. var = %d \n", var);

  int *qvar = (int *)pvar;
  qvar[0] = 1;
  var++;
  printf("2. var = %d \n", var);
  
  printf("中文测试。。。 \n");

  return 0;
}