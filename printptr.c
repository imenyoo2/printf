#include "main.h"

void printptr(void *n, int *ReturnValue)
{
	unsigned int *arg1;
	char arg2;

	arg1 = (unsigned int *) n;
	arg2 = '0';
	printchar(&arg2, ReturnValue);
	arg2 = 'x';
	printchar(&arg2, ReturnValue);
	printhex(arg1, ReturnValue);
}
