#include "stdio.h"
#include "stdint.h"

struct memp{
  struct memp *next;
};
struct memp * memp_tab[5];

uint8_t memp_memory[200];


int main(int argc, char **argv)
{
  struct memp *memp;

  memp = (void *)memp_memory;
  printf("1. memp_memory adderss = 0x%X \n", memp_memory);

  memp_tab[0] = NULL;
  printf("2. memp_tab[0] = 0x%X \n", memp_tab[0]);

  memp->next = memp_tab[0];
  memp_tab[0] = memp;
  printf("3. memp_tab[0] = 0x%X \n", memp_tab[0]);
  printf("4. memp->next = memp_tab[0] = 0x%X \n", memp->next);
  memp = (struct memp *)((uint8_t *)memp + 20);

  memp->next = memp_tab[0];
  memp_tab[0] = memp;
  printf("5. memp_tab[0] = 0x%X \n", memp_tab[0]);
  printf("6. memp->next = memp_tab[0] = 0x%X \n", memp->next); 
  memp = (struct memp *)((uint8_t *)memp + 20);

  memp->next = memp_tab[0];
  memp_tab[0] = memp;
  printf("7. memp_tab[0] = 0x%X \n", memp_tab[0]);
  printf("8. memp->next = memp_tab[0] = 0x%X \n", memp->next);
  memp = (struct memp *)((uint8_t *)memp + 20);

  return 0;
}