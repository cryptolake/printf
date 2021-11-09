#include "main.h"
#include <unistd.h>


/**
 * pchr - print char arg
 * @ap: arg
 *
 **/
char *pchr(va_list ap)
{
	char *s;

	s = malloc(sizeof(char) * 2);

	s[0] = va_arg(ap, int);
	s[1] = '\0';

	return  (s);

}

/**
 * pstr - print string arg
 * @ap: arg
 *
 **/
char *pstr(va_list ap)
{
	char *s;

	s = _strdup(va_arg(ap, char *));

	if (s == NULL)
		s = _strdup("(null)");


	return (s);
}

/**
 * pint - print int arg
 * @ap: arg
 *
 **/
char *pint(va_list ap)
{
	int d;

	d = va_arg(ap, int);
	return (_itoa(d));
}

/**
 * pper - print % arg
 * @ap: arg
 * 
 */
char *pper(va_list ap __attribute__((unused)))
{
	char *s;
	
	s = _strdup("%");
	return (s);
}

/**
 * pbi - print binary arg
 * @ap: arg
 *
 **/
char *pbi(va_list ap)
{
	size_t n;
	char *bin = malloc(sizeof(char));
	int rem, i = 0;

	n = va_arg(ap, size_t);
	while (n!=0) 
  	{
    	rem = n % 2;
    	n /= 2;
    	bin[i++] = rem + '0';
		bin = realloc(bin, i);
  	}
	rev_string(bin);

   return (bin);
}