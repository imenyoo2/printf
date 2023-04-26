#include "main.h"

/**
 * handlePlusAndSpace - to handle the '+' symbol, and ' ' space symbol
 *@printer: pointer to the function printer and his arguments
 *@arg: pointer to the first argument
 *@ReturnValue: pointer to the return value for conter
 *@c: buffer
 */

void handlePlusAndSpace(appParams *params, char c)
{
	int *Buffer;
	char Buffer2 = c;

	Buffer = (int *) params->arg;
	if (*Buffer > 0)
	{
		writeBuffer(params, Buffer2);
		params->printer(params);
	}
	else
	{
		params->printer(params);
	}
}


/**
 * handlePlus - to handle the '+' plus symbol
 *@printer: pointer to the function printer and his arguments
 *@arg: pointer to the first argument
 *@ReturnValue: pointer to the return value for conter
 */

void handlePlus(appParams *params)
{
	handlePlusAndSpace(params, '+');
}

/**
 * handlePlusAndSpace - to handle the ' ' space symbol
 *@printer: pointer to the function printer and his arguments
 *@arg: pointer to the first argument
 *@ReturnValue: pointer to the return value for conter
 */


void handleSpace(appParams *params)
{
	handlePlusAndSpace(params, ' ');
}
