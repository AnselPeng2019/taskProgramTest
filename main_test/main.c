#include "stdio.h"

int main(int argc, char **argv)
{
  int i = 0;
  for(;i<argc;i++)
  {
    printf("%d. argv[%d] = %s \n", i, i, argv[i]);
  }
  i++;
  printf("%d. argc = %d \n", i, argc);
  i++;
  char s[] = "abc";
  printf("%d. s = %s \n", i, s);
  i++;
  printf("%d. sizeof(s) = %d \n", i, sizeof(s));
}