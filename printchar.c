#include "main.h"


/**
 * printint - handle printing of char args for printf
 * @n: pointer to an char type
 * Return: void
 */
void printchar(void *c, int *ReturnValue)
{
	write(1, c, 1);
  *ReturnValue += 1;
}
