#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int _putchar(char c);
void printchar(void *c, int *ReturnValue);
void printint(void *n, int *ReturnValue);
void printhex(void *n, int *ReturnValue);
void printstr(void *n, int *ReturnValue);
void handleArg(const char *options, const char *format, void (*printer)(void *arg, int *returnVaue), void *arg, int *ReturnValue);
#endif
