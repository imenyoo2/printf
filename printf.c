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
	int arg1, check, ReturnValue = 0;
	char *arg2;

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
						handleArg(opstart, format, &printchar, &arg1, &ReturnValue);
						check = 0;
						break;
					}
					case '%':
					{
						arg1 = '%';
						handleArg(opstart, format, &printchar, &arg1, &ReturnValue);
						check = 0;
						break;
					}
					case 'd':
					{
						arg1 = va_arg(ap, int);
						handleArg(opstart, format, &printint, &arg1, &ReturnValue);
						check = 0;
						break;
					}
					case 'i':
					{
						arg1 = va_arg(ap, int);
						handleArg(opstart, format, &printint, &arg1, &ReturnValue);
						check = 0;
						break;
					}
					case 'x':
					{
						arg1 = va_arg(ap, int);
						handleArg(opstart, format, &printhex, &arg1, &ReturnValue);
						check = 0;
						break;
					}
					case 's':
					{
						arg2 = va_arg(ap, char *);
						handleArg(opstart, format, &printstr, &arg2, &ReturnValue);
						check = 0;
						break;
					}
					case 'b':
					{
						arg1 = va_arg(ap, int);
						handleArg(opstart, format, &printbin, &arg1, &ReturnValue);
						check = 0;
						break;
					}
				}
				format++;
			}
		}
		else
		{
		  write(1, format, 1);
		  format++;
			ReturnValue++;
		}
	}
	va_end(ap);
	/* TODO: change functions prototype to be able to modify ReturnValue */
	return (ReturnValue);
}

/**
 * handleArg - handles the printing of arg and format options of printf
 * @options: the pointer to the start of format options
 * @format: pointer to the end of the format options (format character)
 * @printer: the adequate print function for arg
 * @arg: argument to be printed
 * @ReturnValue: pointer to the return value of printf
 * Return: void
 */
void handleArg(
				const char *options,
				const char *format,
				void (*printer)(void *arg, int *ReturnValue),
				void *arg,
				int *ReturnValue)
{
	if (options < format)
	{
		/* TODO: handle options */
	}
	else
	{
		printer(arg, ReturnValue);
	}
}
