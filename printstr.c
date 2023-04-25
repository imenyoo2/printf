#include "main.h"


/**
 * printstr - handle printing of args of type string for printf
 * @c: string type
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */
void printstr(void *c, int *ReturnValue)
{
	char **str;

	str = (char **) c;
	while (**str != '\0')
	{
		printchar(*str, ReturnValue);
		*str += 1;
	}
}
