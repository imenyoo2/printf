#include "main.h"

void printint(void *n)
{
  char arg;
  int arg2;
  int *arg3;

  arg3 = (int *) n;
  if (*arg3 < 10)
  {
    arg = '0' + *arg3;
    printchar(&arg);
  }
  else
  {
    arg2 = *arg3 / 10;
    printint(&arg2);
    arg = '0' + *arg3 % 10;
    printchar(&arg);
  }
}
