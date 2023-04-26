#include "main.h"

/**
 * printchar - handle printing of char args for printf
 * @c: pointer to an char type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */

void printchar(appParams *params)
{
	writeBuffer(params, *((char *) params->arg));
}
