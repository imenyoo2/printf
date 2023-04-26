#include "main.h"

/**
 * printhex - handle printing of int args in hex format for printf
 * @n: pointer to an int type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */

void printhex(appParams *params)
{
	char arg;
	unsigned int arg2;
	unsigned int *arg3;
	char arr[] = {'f', 'e', 'd', 'c', 'b', 'a'};

	arg3 = (unsigned int *) params->arg;
	if (*arg3 < 10)
	{
		arg = '0' + *arg3;
		writeBuffer(params, arg);
	}
	else if (*arg3 < 16)
	{
		arg = arr[15 - *arg3];
		writeBuffer(params, arg);
	}
	else
	{
		arg2 = *arg3 % 16;
		*arg3 = *arg3 / 16;
		printhex(params);
		*arg3 = arg2;
		printhex(params);
	}
}

/**
 * printLhex - handle printing of int args in long hex format for printf
 * @n: pointer to an int type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */

void printLhex(appParams *params)
{
	char arg;
	unsigned long arg2;
	unsigned long *arg3;
	char arr[] = {'f', 'e', 'd', 'c', 'b', 'a'};

	arg3 = (unsigned long *) params->arg;
	if (*arg3 < 10)
	{
		arg = '0' + *arg3;
		writeBuffer(params, arg);
	}
	else if (*arg3 < 16)
	{
		arg = arr[15 - *arg3];
		writeBuffer(params, arg);
	}
	else
	{
		arg2 = *arg3 % 16;
		*arg3 = *arg3 / 16;
		printhex(params);
		*arg3 = arg2;
		printhex(params);
	}
}

/**
 * printHex - handle printing of int args in hex format
 * and upper case characters for printf
 * @n: pointer to an int type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */

void printHex(appParams *params)
{
	char arg;
	unsigned int arg2;
	unsigned int *arg3;
	char arr[] = {'F', 'E', 'D', 'C', 'B', 'A'};

	arg3 = (unsigned int *) params->arg;
	if (*arg3 < 10)
	{
		arg = '0' + *arg3;
		writeBuffer(params, arg);
	}
	else if (*arg3 < 16)
	{
		arg = arr[15 - *arg3];
		writeBuffer(params, arg);
	}
	else
	{
		arg2 = *arg3 % 16;
		*arg3 = *arg3 / 16;
		printhex(params);
		*arg3 = arg2;
		printhex(params);
	}
}

/**
 * printLHex - handle printing of int args in long hex format
 * and upper case characters for printf
 * @n: pointer to an int type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */

void printLHex(appParams *params)
{
	char arg;
	unsigned long arg2;
	unsigned long *arg3;
	char arr[] = {'F', 'E', 'D', 'C', 'B', 'A'};

	arg3 = (unsigned long *) params->arg;
	if (*arg3 < 10)
	{
		arg = '0' + *arg3;
		writeBuffer(params, arg);
	}
	else if (*arg3 < 16)
	{
		arg = arr[15 - *arg3];
		writeBuffer(params, arg);
	}
	else
	{
		arg2 = *arg3 % 16;
		*arg3 = *arg3 / 16;
		printhex(params);
		*arg3 = arg2;
		printhex(params);
	}
}
