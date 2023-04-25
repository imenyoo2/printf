#include "main.h"

void printptr(void *n, int *ReturnValue)
{
	long unsigned int *arg1;
	char arg2;

	arg1 = (long unsigned int *) n;
	arg2 = '0';
	printchar(&arg2, ReturnValue);
	arg2 = 'x';
	printchar(&arg2, ReturnValue);
	printhex(arg1, ReturnValue);
}
