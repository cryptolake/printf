#include "main.h"

void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}


int _printf(const char *format, ...)
{
	char *s;
	int l = 0;

	types ops[] = {
	{'c', pchr},
	{'s', pstr},
	{'i', pint},
	{'d', pint},
	{'%', pper},
	{'b', pbi},
	{'o', poct},
	{'u', punsign},
	{'x', phex},
	{'X', pheX},
	{0, NULL}
	};

	int i = 0, j = 0;

	va_list ap;
	

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