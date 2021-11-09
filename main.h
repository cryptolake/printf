#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef unsigned long int size_t;

typedef struct {
	char tp;
	char *(*f)(va_list ap);

} types;

char *pchr(va_list ap);
char *pstr(va_list ap);
char *pint(va_list ap);
char *pper(va_list ap);
char *pbi(va_list ap);
char *punsign(va_list ap);
char *poct(va_list ap);
char *phex(va_list ap);
char *pheX(va_list ap);

char *from_dec(size_t n, int base, int maj);

char *_strdup(char *str);

int _printf(const char *format, ...);

int _strlen(const char *s);

char *_strcpy(char *dest, char *src);
char *_itoa(int d);
char *_itoau(size_t n);
void rev_string(char *s);
#endif
