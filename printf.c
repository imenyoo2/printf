#include "main.h"
#include <unistd.h>
#include <stdarg.h>


int _printf(const char *format, ...)
{
  const char *opstart;
  va_list ap;
  int arg1, check;
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

void handleArg(const char *options, const char *format, void (*printer)(void *arg), void *arg)
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
