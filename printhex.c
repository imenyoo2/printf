#include "main.h"

/**
 * printhex - handle printing of int args in hex format for printf
 * @n: pointer to an int type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */
void printhex(void *n, int *ReturnValue)
{
	char arg;
	int arg2;
	int *arg3;
	char arr[] = {'f', 'e', 'd', 'c', 'b', 'a'};

	arg3 = (int *) n;
	if (*arg3 < 0)
	{
		arg = '-';
		printchar(&arg, ReturnValue);
		*arg3 *= -1;
		printhex(arg3, ReturnValue);
	}
	else if (*arg3 < 10)
	{
		arg = '0' + *arg3;
		printchar(&arg, ReturnValue);
	}
	else if (*arg3 < 16)
	{
		arg = arr[15 - *arg3];
		printchar(&arg, ReturnValue);
	}
	else
	{
		arg2 = *arg3 / 16;
		printhex(&arg2, ReturnValue);
		arg2 = *arg3 % 16;
		printhex(&arg2, ReturnValue);
	}
}

void printHex(void *n, int *ReturnValue)
{
	char arg;
	int arg2;
	int *arg3;
	char arr[] = {'F', 'E', 'D', 'C', 'B', 'A'};

	arg3 = (int *) n;
	if (*arg3 < 0)
	{
		arg = '-';
		printchar(&arg, ReturnValue);
		*arg3 *= -1;
		printhex(arg3, ReturnValue);
	}
	else if (*arg3 < 10)
	{
		arg = '0' + *arg3;
		printchar(&arg, ReturnValue);
	}
	else if (*arg3 < 16)
	{
		arg = arr[15 - *arg3];
		printchar(&arg, ReturnValue);
	}
	else
	{
		arg2 = *arg3 / 16;
		printhex(&arg2, ReturnValue);
		arg2 = *arg3 % 16;
		printhex(&arg2, ReturnValue);
	}

}
