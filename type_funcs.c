#include "main.h"
#include <unistd.h>
#include <stdio.h>


/**
 * pchr - print char arg
 * @ap: arg
 *
 **/
char *pchr(va_list ap)
{
	char *s;

	s = malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);

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
	char *s;

	d = va_arg(ap, int);
	if (d == 0)
	{
		s = _strdup("0");
		return(s);
	}
	s = _itoa(d);
	
	return (s);
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
	char *bin;
	int rem = 0, i = 0;

	n = va_arg(ap, size_t);
	if (n == 0)
	{
		bin = _strdup("0");
		return (bin);
	}

	
	bin = malloc(sizeof(char));
	
	while (n!=0)
  	{
    	rem = n % 2;
    	n /= 2;
		bin = realloc(bin, i + 1);
		if (bin == NULL)
			return (NULL);
    	bin[i++] = rem + '0';
  	}
	/* printf("\ni = %d\n",i); */
	bin = realloc(bin, i + 1);
	bin[i] = '\0';
	rev_string(bin);


   return (bin);
}