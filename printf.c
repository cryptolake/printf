#include "main.h"

int _putchar(char c)
{
	return(write(1, &c, 1));
}


int _printf(const char *format, ...)
{
	char *s;
	int l;

	types ops[] = {
	{'c', pchr},
	{'s', pstr},
	{'i', pint},
	{'d', pint},
	{'%', pper},
	{0, NULL}
	};
	int i = 0, j = 0, d = 0;

	va_list ap;
	va_start(ap, format);
	
	if (_strlen(format) == 1 && format[i] == '%')
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
				s = ops[j].f(ap);
				l += _strlen(s);
		    	
				write(STDOUT_FILENO, s, _strlen(s));
				free(s);
				i += 2;
			}
			else 
			{
				d = _putchar(format[i]);
				i += d;
				l += d;
			}
		}
		else
		{
			d = _putchar(format[i]);
			i += d;
			l += d;
		}
	}
	va_end(ap);
	return (l);
}