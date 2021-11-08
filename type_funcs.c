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
	/* size_t n;
	size_t bin = 0;
	int rem, i = 1;

	n = va_arg(ap, size_t);
	while (n!=0) 
  	{
    	rem = n % 2;
    	n /= 2;
    	bin += rem * i;
    	i *= 10;
  	}

   return (_itoau(bin)); */
    char *bin;
	unsigned int k;
	int i = 0;

	k = va_arg(ap, unsigned int);
   bin = (char *)malloc(sizeof(char));
   while(k > 0) {
      bin [i] = (k % 2) + '0';
      k = k/2;
      bin = (char *)realloc(bin, sizeof(char) * (sizeof(bin)+1));
	i++;
   }
   bin[sizeof(bin)-1] = '\0';

   return (bin);
}