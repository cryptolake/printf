#include "main.h"
#include <unistd.h>


/**
 * _printf - function that produces output according to a format
 * @format: format of printf
 *
 * Return: length of printed chars or -1 on failure
 **/
int _printf(const char *format, ...)
{
	char *s, *si;
	int l = 0, i = 0, j = 0, k = 0, x = 0;
	va_list ap;
	types ops[] = {{'c', pchr}, {'s', pstr}, {'i', pint}, {'d', pint},
		{'%', pper}, {'b', pbi}, {'o', poct}, {'u', punsign},
		{'x', phex}, {'X', pheX}, {'r', prev},{'R', prot}, {0, NULL}};

	if (format == NULL || (_strlen(format) == 1 && format[i] == '%'))
		return (-1);
	va_start(ap, format);
	s = malloc(0);
	if (s == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;

			while (ops[j].tp && ops[j].tp != format[i + 1])
				j++;

			if (ops[j].tp == format[i + 1])
			{
				si = ops[j].f(ap);
				if (si == NULL)
				{
					free(s);
					free(si);
					return (-1);
				}

				s = _realloc(s, k, (k + _strlen(si)));
				if (s == NULL)
				{
					free(s);
					free(si);
					return (-1);
				}

				x = 0;
				if (ops[j].tp == 'c' && si[0] == '\0')
					x = 1;

				for (l = 0; l < _strlen(si) + x; l++)
					s[k++] = si[l];

				free(si);
				i += 2;
			}
			else
			{
				s = _realloc(s, k, k + 1);
				if (s == NULL)
				{
					free(s);
					return (-1);
				}
				s[k++] = format[i++];
			}
		}
		else
		{
			s = _realloc(s, k, k + 1);
			if (s == NULL)
			{
				free(s);
				return (-1);
			}
			s[k++] = format[i++];
		}
	}
	va_end(ap);

	l = write(STDOUT_FILENO, s, k);

	free(s);
	return (l);
}
