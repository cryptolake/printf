#include "main.h"

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
	{0, NULL}
	};
	int i = 0, j = 0;

	va_list ap;
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
			
		}
		
		s = malloc(sizeof(char));
		s[0] = format[i];
		write(STDOUT_FILENO, s, 1);
		free(s);
		i++;
		l++;
	}
	return (l);
}