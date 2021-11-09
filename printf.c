#include "main.h"


/**
 * _printf - function that produces output according to a format
 * @format: format of printf
 *
 * Return: length of printed chars or -1 on failure
 **/
int _printf(const char *format, ...)
{

	char *s;
	int l = 0, i = 0, j = 0;
	va_list ap;
	types ops[] = {{'c', pchr}, {'s', pstr}, {'i', pint}, {'d', pint},
					{'%', pper}, {'b', pbi}, {'o', poct}, {'u', punsign},
					{'x', phex}, {'X', pheX}, {0, NULL}
	};


	if (format == NULL || (_strlen(format) == 1 && format[i] == '%'))
		return (-1);

	va_start(ap, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (ops[j].tp && ops[j].tp != format[i + 1])
				j++;

			if (ops[j].tp == format[i + 1])
			{
				s = ops[j].f(ap);
				if (s == NULL)
					return (-1);
				l += _strlen(s);

				write(STDOUT_FILENO, s, _strlen(s));
				free(s);
				i += 2;
			}
			else
			{
				_putchar(format[i]);
				i++;
				l++;
			}
		}
		else
		{
			_putchar(format[i]);
			i++;
			l++;
		}
	}
	va_end(ap);
	return (l);
}
