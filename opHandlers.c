#include "main.h"

void handlePlusAndSpace(
		void (*printer)(void *arg, int *ReturnValue),
		void *arg,
		int *ReturnValue,
		char c)
{
	int *buffer;
	char buffer2 = c;

	buffer = (int *) arg;
	if (*buffer > 0)
	{
		printchar(&buffer2, ReturnValue);
		printer(arg, ReturnValue);
	}
	else
	{
		printer(arg, ReturnValue);
	}
}

void handlePlus(
		void (*printer)(void *arg, int *ReturnValue),
		void *arg,
		int *ReturnValue)
{
	handlePlusAndSpace(printer, arg, ReturnValue, '+');
}

void handleSpace(
		void (*printer)(void *arg, int *ReturnValue),
		void *arg,
		int *ReturnValue)
{
	handlePlusAndSpace(printer, arg, ReturnValue, ' ');
}
