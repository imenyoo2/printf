
#include "main.h"

/**
 * printun - handle printing of int args for printf
 * @n: pointer to an int type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */

void printun(appParams *params)
{
	char arg;
	unsigned int *arg3;

	arg3 = (unsigned int *) params->arg;
	if (*arg3 < 10)
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
