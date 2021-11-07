#include "main.h"
#include <stdio.h>

int main()
{
	char *s;
	s = _itoa(99);
	printf("99 = %s\n", s);

	s = _itoa(0);
	printf("0 = %s\n", s);


	return (0);
}
