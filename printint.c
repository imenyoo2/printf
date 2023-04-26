#include "main.h"

/**
 * printint - handle printing of int args for printf
 * @n: pointer to an int type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */

void printint(appParams *params)
{
	char arg;
	int *arg3;

	arg3 = (int *) params->arg;
	if (*arg3 < 0)
	{
		arg = '-';
		writeBuffer(params, arg);
		*arg3 *= -1;
		printint(params);
	}
	else if (*arg3 < 10)
	{
		arg = '0' + *arg3;
		writeBuffer(params, arg);
	}
	else
	{
		arg = '0' + *arg3 % 10;
		*arg3 = *arg3 / 10;
		printint(params);
		writeBuffer(params, arg);
	}
}
