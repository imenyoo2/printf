#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>

typedef struct params {
	void (*printer)(struct params *param);
	void *arg;
	int *ReturnValue;
	int *buffer;
	int *position;

} appParams;

int _printf(const char *format, ...);
int _putchar(char c);
void printchar(appParams *params);
void printint(appParams *params);
void printbin(appParams *params);
void printun(appParams *params);
void printoct(appParams *params);
void printhex(appParams *params);
void printLhex(appParams *params);
void printHex(appParams *params);
void printLHex(appParams *params);
void printstr(appParams *params);
void printStr(appParams *params);
void printptr(appParams *params);
int containes(const char *start, const char *end, char c);
void handlePlusAndSpace(appParams *params, char c);
void handlePlus(appParams *params);
void handleSpace(appParams *params);
void handleHash(appParams *params);

void handleArg(appParams *params, const char *options, const char *format);

void writeBuffer(appParams *params, char c);

int checkKnown(const char *format);
#endif
