#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

int main(int argc, char** argv)
{
  time_t now;
  struct tm *nowTime;

  time(&now);//获取当前时间
  nowTime = localtime(&now);//格式化当前时间
  printf("now's address is %X.\n", &now);
  printf("nowTime is %X.\n", nowTime);

  int wd = nowTime->tm_wday;//提取当前周几
  int yd = nowTime->tm_yday;//提取当前为本年的第几天
  int year = nowTime->tm_year + 1900;

  int base = 7 - (yd + 1 -(wd + 1)) % 7;//计算本年的第一天是周几
  if(base == 7)
    base = 0;
  
  int nweek = (base + yd) / 7 + 1;//计算今天是本年的第几周

  char nweeks[5] = "";
  int yearOffset = (year - 2000) * 100;
  itoa(nweek+yearOffset, nweeks,10);//将当天的周数转换成字符串，也可以用sprintf函数来实现
  printf("1. This nweek is : %s week \n",  nweeks);

 
  char fileName[10] = "2101.pptx";//留出字符串最后的结束符空间
  for(int i=0;i<4;i++)
  {
    fileName[i] = nweeks[i];//重新生成文件名为当前周数
  }
  printf("2. PPTX filename is : %s \n",  fileName);

  char path[] = "C:\\Users\\Xiaofei\\Desktop\\";  /* C:\\Users\\Xiaofei\\Desktop\\ */
  // char *path = getcwd(NULL,0);
  printf("3. absolute path is : %s \n",  path);

  char *fullFName = malloc(strlen(nweeks)+strlen(path)+1);
  if(fullFName == NULL)
  {
    printf("Error : Fail to create file name ! \n");
    return -1;
  }
  strcpy(fullFName, path);
  strcat(fullFName, fileName);

  printf("4. full path with file name is : %s \n",  fullFName);

  FILE *fp = fopen(fullFName, "a");

  if(fp == NULL)
  printf("ERROR : file create failed.\n");

  fclose(fp);

  free(fullFName);
  free(nowTime);
  getchar();

  return 0;
}