#include "main.h"

/**
 * printbin - handle printing of int args in binary format for printf
 * @n: pointer to an int type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */
void printbin(appParams *params)
{
	char arg;
	unsigned int mask = 1;
	unsigned int *arg3;

	arg3 = (unsigned int *) params->arg;
	if (*arg3)
	{
		if (*arg3 & mask)
		{
			*arg3 = *arg3 >> 1;
			printbin(params);
			arg = '1';
			writeBuffer(params, arg);
		}
		else
		{
			*arg3 = *arg3 >> 1;
			printbin(params);
			arg = '0';
			writeBuffer(params, arg);
		}
	}
}
