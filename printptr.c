#include "main.h"

/**
 * printptr - a function that print pointer to standard output
 * @n: pointer passed as pointer
 * @ReturnValue: lenth of output format
 */

void printptr(appParams *params)
{
	char arg2;

	arg2 = '0';
	writeBuffer(params, arg2);
	arg2 = 'x';
	writeBuffer(params, arg2);
	printLhex(params);
}
