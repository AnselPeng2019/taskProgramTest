#include "stdio.h"

int main(int argc, char **argv)
{
  int a = 2;
  int b = 2;
  if(a < b)
  {
    goto _label_a;
  }
  else if(a == b)
  {
    goto _label_b;
  }

  _label_a :
  printf("1. a < b. \n");
  _label_b :
  printf("2. a == b. \n");

  printf("程序结束.\n");
  return 0;
}