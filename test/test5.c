#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%s\n", "heyyyy this \0 is a trick ");
	len2 = printf("%s\n", "heyyyy this \0 is a trick ");
	fflush(stdout);
	printf("len1 = %d\n, len2 = %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
