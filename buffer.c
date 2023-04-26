#include "main.h"

void writeBuffer(appParams *params, char c)
{
	int i;

	params->buffer[*params->position] = c;
	*(params->ReturnValue) += 1;
	*(params->position) += 1;

	if (*(params->position) == 1024)
	{
		write(1, params->buffer, 1024);
		*(params->position) = 0;
	}
	else if (c == '\0')
	{
		for (i = *(params->position); i < 1024; i++)
		{
			params->buffer[i] = '\0';
		}
		write(1, params->buffer, 1024);
	}
}
