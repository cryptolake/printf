#include "main.h"
#include <unistd.h>
#include <stdio.h>


/**
 * pchr - return char arg
 * @ap: arg
 * Return: char
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
 * pstr - return string arg
 * @ap: arg
 * Return: char
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
 * pint - return int arg
 * @ap: arg
 * Return: char
 **/
char *pint(va_list ap)
{
	int d;
	char *s;

	d = va_arg(ap, int);
	if (d == 0)
	{
		s = _strdup("0");
		return (s);
	}
	s = _itoa(d);
	return (s);
}

/**
 * pper - return % arg
 * @ap: arg
 * Return: char
 */
char *pper(va_list ap __attribute__((unused)))
{
	char *s;

	s = _strdup("%");
	return (s);
}

/**
 * pbi - return binary arg
 * @ap: arg
 * Return: char
 **/
char *pbi(va_list ap)
{
	sizet n;
	char *s;

	n = va_arg(ap, sizet);
	s = from_dec(n, 2, 0);
	return (s);
}

/**
 * poct - return octal arg
 * @ap: arg
 * Return: char
 **/
char *poct(va_list ap)
{
	sizet n;
	char *s;

	n = va_arg(ap, sizet);
	s = from_dec(n, 8, 0);
	return (s);
}

/**
 * pheX - return hex arg
 * @ap: arg
 * Return: char
 **/
char *pheX(va_list ap)
{
	sizet n;
	char *s;

	n = va_arg(ap, sizet);
	s = from_dec(n, 16, 1);
	return (s);
}

/**
 * phex - return hex arg
 * @ap: arg
 * Return: char
 **/
char *phex(va_list ap)
{
	sizet n;
	char *s;

	n = va_arg(ap, sizet);
	s = from_dec(n, 16, 0);
	return (s);
}

/**
 * punsign - return unsigned int arg in string
 * @ap: arg
 * Return: char
 **/
char *punsign(va_list ap)
{
	sizet d;
	char *s;

	d = va_arg(ap, sizet);
	if (d == 0)
	{
		s = _strdup("0");
		return (s);
	}

	s = _itoau(d);

	return (s);
}


/**
 * prev - return reversed string
 * @ap: arg
 * Return: char
 **/
char *prev(va_list ap)
{
	char *s;
	s = _strdup(va_arg(ap, char *));
	if (s == NULL)
		return (NULL);

	return(rev_string(s));

}



/**
 * prot - return string in rot13
 * @ap: arg
 * Return: char
 **/
char *prot(va_list ap)
{
	char *s;
	s = _strdup(va_arg(ap, char *));
	if (s == NULL)
		return (NULL);

	return(rot13(s));
}
