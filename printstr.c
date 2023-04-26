#include "main.h"

/**
 * printstr - handle printing of args of type string for printf
 * @c: string type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */

void printstr(appParams *params)
{
	char **str;

	str = (char **) params->arg;
	while (**str != '\0')
	{
		writeBuffer(params, **str);
		*str += 1;
	}
}

/**
 * printStr - handle printing of args of type
 * string in upper case characters for printf
 * @c: string type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */

void printStr(appParams *params)
{
	char **str;
	char Buffer;

	str = (char **) params->arg;
	while (**str != '\0')
	{
		if ((**str > 0 && **str < 32) || (**str >= 127))
		{
			Buffer = '\\';
			writeBuffer(params, Buffer);
			Buffer = 'x';
			writeBuffer(params, Buffer);
		}
		else
		{
			writeBuffer(params, **str);
		}
		*str += 1;
	}
}
