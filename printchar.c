#include "main.h"


/**
 * printint - handle printing of char args for printf
 * @n: pointer to an char type
 * Return: void
 */
void printchar(void *c)
{
	write(1, c, 1);
}
