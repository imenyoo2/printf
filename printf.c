#include "main.h"


/* TODO: check Return alwayse 0 */
/**
 * _printf - prints the formated string format
 * @format: formated string
 * Return: alwayse 0
 */
int _printf(const char *format, ...)
{
	const char *opstart;
	va_list ap;
	int arg1, check;
#if 0
	char *arg2;
#endif

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			opstart = ++format;
			check = 1;
			while (check)
			{
				switch (*format)
				{
					case 'c':
					{
						arg1 = va_arg(ap, int);
						handleArg(opstart, format, &printchar, &arg1);
						check = 0;
						break;
					}
					case '%':
					{
						arg1 = '%';
						handleArg(opstart, format, &printchar, &arg1);
						check = 0;
						break;
					}
					case 'd':
					{
						arg1 = va_arg(ap, int);
						handleArg(opstart, format, &printint, &arg1);
						check = 0;
						break;
					}
					case 'i':
					{
						arg1 = va_arg(ap, int);
						handleArg(opstart, format, &printint, &arg1);
						check = 0;
						break;
					}
#if 0
					case 'x':
					{
						arg1 = va_arg(ap, int);
						handleArg(opstart, format, &printhex, &arg1);
						check = 0;
						break;
					}
					case 's':
					{
						arg2 = va_arg(ap, char *);
						handleArg(opstart, format, &printstr, &arg2);
						check = 0;
						break;
					}
#endif
				}
				format++;
			}
		}
		else
		{
		  write(1, format, 1);
		  format++;
		}
	}
	va_end(ap);
	/* TODO: need to return int based on behaviour */
	return (0);
}

/**
 * handleArg - handles the printing of arg and format options of printf
 * @options: the pointer to the start of format options
 * @format: pointer to the end of the format options (format character)
 * @printer: the adequate print function for arg
 * @arg: argument to be printed
 * Return: void
 */
void handleArg(
				const char *options,
				const char *format,
				void (*printer)(void *arg),
				void *arg)
{
	if (options < format)
	{
		/* TODO: handle options */
	}
	else
	{
		printer(arg);
	}
}