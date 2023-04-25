#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int _putchar(char c);
void printchar(void *c);
void printint(void *n);
void printhex(void *n);
void printstr(void *n);
void handleArg(const char *options, const char *format, void (*printer)(void *arg), void *arg);
#endif
