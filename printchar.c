#include "main.h"


/**
 * printint - handle printing of char args for printf
 * @n: pointer to an char type
 * Return: void
 */
void printchar(void *c, int *returnValue)
{
	write(1, c, 1);
  *returnValue += 1;
}
