#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
typedef unsigned int sizet;

typedef struct {
	char tp;
	char *(*f)(va_list ap);

} types;

void _putchar(char c);

/* Return string from specified type */
char *pchr(va_list ap);
char *pstr(va_list ap);
char *pint(va_list ap);
char *pper(va_list ap);
char *pbi(va_list ap);
char *punsign(va_list ap);
char *poct(va_list ap);
char *phex(va_list ap);
char *pheX(va_list ap);
char *prev(va_list ap);
char *prot(va_list ap);

/* Standard functions */
char *from_dec(sizet n, sizet base, sizet maj);
char *_strdup(char *str);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_itoa(int d);
char *_itoau(sizet n);
char *rev_string(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *rot13(char *s);

#endif
