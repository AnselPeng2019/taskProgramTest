#include "stdio.h"
#include "stdint.h"
#include "add.h"

typedef struct {
uint8_t  gain : 1;
uint16_t pd   : 8;
}Config_t;

int main()
{
  Config_t cfg;

  cfg.gain = 1;
  cfg.pd   = 3;

  printf("结构体长度是 %d 个字节\n", sizeof(cfg));
  uint8_t *p = (uint8_t *)&cfg;
  printf("第一个字节内容是 0x%2x \n", p[0]);
  
  printf("gain + pd = %d \n", add2((int)cfg.gain , (int)cfg.pd));
  return 0;
}