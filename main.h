#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct {
	char tp;
	char *(*f)(va_list ap);

} types;

char *pchr(va_list ap);
char *pstr(va_list ap);
char *pint(va_list ap);

int _printf(const char *format, ...);

int _strlen(char *s);

char *_strcpy(char *dest, char *src);
char *_itoa(int d);

#endif
