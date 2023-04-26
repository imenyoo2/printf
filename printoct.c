#include "main.h"

/**
 * printoct - handle printing of int args in octal formate for printf
 * @n: pointer to an int type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */
void printoct(appParams *params)
{
	char arg;
	unsigned int *arg3;

	arg3 = (unsigned int *) params->arg;
	if (*arg3 < 8)
	{
		arg = '0' + *arg3;
		writeBuffer(params, arg);
	}
	else
	{
		arg = '0' + *arg3 % 8;
		*arg3 = *arg3 / 8;
		printoct(params);
		writeBuffer(params, arg);
	}
}
