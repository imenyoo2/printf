#include "main.h"


/* TODO: check Return alwayse 0 */
/**
 * _printf - prints the formated string format
 * @format: formated string
 * @...: variadic arguments
 * Return: alwayse 0
 */

int _printf(const char *format, ...)
{
	const char *opstart;
	va_list ap;
	int arg1, check, ReturnValue = 0;
	char *arg2;
	int *arg3, position = 0;
	int buffer[1024];
	/* char *p = buffer; */
	appParams params;

	params.ReturnValue = &ReturnValue;
	params.buffer = buffer;
	params.position = &position;
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
						params.arg = &arg1;
						params.printer = &printchar;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
					case '%':
					{
						arg1 = '%';
						params.arg = &arg1;
						params.printer = &printchar;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
					case 'd':
					{
						arg1 = va_arg(ap, int);
						params.arg = &arg1;
						params.printer = &printint;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
					case 'o':
					{
						arg1 = va_arg(ap, int);
						params.arg = &arg1;
						params.printer = &printoct;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
					case 'i':
					{
						arg1 = va_arg(ap, int);
						params.arg = &arg1;
						params.printer = &printint;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
					case 'x':
					{
						arg1 = va_arg(ap, int);
						params.arg = &arg1;
						params.printer = &printhex;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
					case 'X':
					{
						arg1 = va_arg(ap, int);
						params.arg = &arg1;
						params.printer = &printHex;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
					case 's':
					{
						arg2 = va_arg(ap, char *);
						params.arg = &arg2;
						params.printer = &printstr;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
					case 'S':
					{
						arg2 = va_arg(ap, char *);
						params.arg = &arg2;
						params.printer = &printStr;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
					case 'b':
					{
						arg1 = va_arg(ap, int);
						params.arg = &arg1;
						params.printer = &printbin;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
					case 'u':
					{
						arg1 = va_arg(ap, int);
						params.arg = &arg1;
						params.printer = &printun;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
					case 'p':
					{
						arg3 = va_arg(ap, int *);
						params.arg = &arg3;
						params.printer = &printptr;
						handleArg(&params, opstart, format);
						check = 0;
						break;
					}
				}
				if (!checkKnown(format) && check)
				{
					arg1 = '%';
					writeBuffer(&params, arg1);
					format = opstart;
					break;
				}
				format++;
			}
		}
		else
		{
			writeBuffer(&params, *format);
		  format++;
		}
	}
	va_end(ap);
	writeBuffer(&params, '\0');
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
void handleArg(appParams *params, const char *options, const char *format)
{
	char op[] = {'+', ' ', '#'};
	/* array of handler functions */
	void (*handlers[])(appParams *param) = {&handlePlus, &handleSpace/*, &handleHash*/};
	int i;

	if (options < format)
	{
		for (i = 0; i < 3; i++)
		{
			if (containes(options, format, op[i]))
			{
				handlers[i](params);
			}
		}
	}
	else
	{
		params->printer(params);
	}
}

/**
 * containes - check for a char in string buffer passed by pointer adresse
 * @start: pointer to the start
 * @end: pointer to the end
 * @c: argument to be printed
 * Return: 1 if success, 0 if non
 */

int containes(const char *start, const char *end, char c)
{
	const char *buffer = start;

	while (buffer < end)
	{
		if (*buffer == c)
		{
			return (1);
		}
		buffer++;
	}
	return (0);
}

/**
 * checkKnown - handles the printing of arg and format options of printf
 * @format: the pointer to the format specifier of _printf function
 * Return: 1 if success, 0 if non
 */

int checkKnown(const char *format)
{
	char known[] = {'+', '#', '-', ' ', '.'};
	int i;

	for (i = 0; i < 5; i++)
	{
		if (*format == known[i])
		{
			return (1);
		}
	}
	for (i = 0; i < 10; i++)
	{
		if (*format == '0' + i)
		{
			return (1);
		}
	}
	return (0);
}
