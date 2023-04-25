#include "main.h"

/**
 * printint - handle printing of int args for printf
 * @n: pointer to an int type
 * Return: void
 */
void printint(void *n, int *returnValue)
{
	char arg;
	int arg2;
	int *arg3;

	arg3 = (int *) n;
	if (*arg3 < 10)
	{
		arg = '0' + *arg3;
		printchar(&arg, returnValue);
	}
	else
	{
		arg2 = *arg3 / 10;
		printint(&arg2, returnValue);
		arg = '0' + *arg3 % 10;
		printchar(&arg, returnValue);
	}
}
