#include "main.h"

/**
 * _putchar - print char to stdout
 * @c: char
 *
 **/
void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}


/**
 * _strlen - get length of string
 *
 * @s: string
 *
 * Return: length
 **/
int _strlen(const char *s)
{
	int i = 0;
	if (s[i] == '\0' && s[i+1] == '\0')
		return (1);

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strcpy - copy a string to another string
 *
 * @dest: destination
 * @src: source
 *
 * Return: pointer string
 **/
char *_strcpy(char *dest, char *src)
{
	int l, i;

	l = _strlen(src);

	for (i = 0; i <= l; i++)
	{
		dest[i] = src[i];
	}

	return (src);
}

/**
 * _strdup - duplicate string in new memory addr
 * @str: string
 *
 * Return: new string addr
 **/
char *_strdup(char *str)
{
	char *s;
	unsigned int l, i;


	if (str == NULL)
	{
		return (NULL);
	}

	else
	{

		l = _strlen(str);
		s = malloc(l + 1);
		if (s == NULL)
		{
			return (NULL);
		}
		for (i = 0; i <= l; i++)
		{
			s[i] = str[i];
		}

	}

	return (s);
}
/**
* _abs - return absolute value
* @n: number
*
* Return: absolute value
**/
int _abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}


/**
 * count_d10 - count number of digits
 *
 * @n: number
 *
 * Return: 10^count-1
 **/
int count_d10(int n)
{
	int x;

	x = 1;
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		x *= 10;
	}
	return (x);
}

/**
 * _itoa - int to str
 *
 * @n: number
 * Return: string
 **/
char *_itoa(int n)
{
	char *s;
	int x = 0,
	y = 0,
	c = 0,
	i = 0,
	b = _abs(n),
	l = 0,
	e = 1;

	while (b != 0)
	{
		b /= 10;
		l++;
	}

	x = count_d10(n);
	if (n < 0)
	{
		y = 1;
		e = -1;
	}

	s = malloc(sizeof(char) * (l + y + 1));
	if (s == NULL)
		return (NULL);

	if (n < 0)
		s[i++] = '-';

	while (x != 0)
	{
		c = e * ((n / x) % 10) + '0';
		x /= 10;
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	return (s);
}

/**
 * _itoau - unsigned int to str
 *
 * @n: number
 * Return: string
 **/
char *_itoau(sizet n)
{
	char *s;
	sizet x = 0,
	y = 0,
	c = 0,
	i = 0,
	b = _abs(n),
	l = 0;

	while (b != 0)
	{
		b /= 10;
		l++;
	}

	x = count_d10(n);


	s = malloc(sizeof(char) * (l + y + 1));
	if (s == NULL)
		return (NULL);

	while (x != 0)
	{
		c = ((n / x) % 10) + '0';
		x /= 10;
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	return (s);
}

/**
 * swap - swap two variables
 *
 * @a: first var
 * @b: second var
 **/
void swap(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}


/**
 * rev_string - reverse string
 *
 * @s: string
 **/
char *rev_string(char *s)
{
   int n = _strlen(s);
   int i;
 

	for (i = 0; i < n / 2; i++)
		swap(&s[i], &s[n - i - 1]);

	return (s);
}

/**
* reval - return char value from integer
* 
* @num: value
* @maj: uppercase or not
* Return: char
**/

char reval(int num, int maj)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else if (maj)
		return (char)(num - 10 + 'A');
	else
		return (char)(num - 10 + 'a');
}




/**
* from_dec - convert to decimal any base
*
* @n: number
* @base: base
* @maj: uppercase or not
*
* Return: string
**/
char *from_dec(sizet n, int base, int maj)
{
	char *s;
	int rem = 0, i = 0;

	if (n == 0)
	{
		s = _strdup("0");
		return (s);
	}

	
	s = malloc(0);
	
	while (n!=0)
  	{
		rem = n % base;
		n /= base;
		s = _realloc(s, i, i + 1);
		if (s == NULL)
			return (NULL);
		s[i++] = reval(rem, maj);
  	}
	s = _realloc(s, i, i + 1);
	s[i] = '\0';
	rev_string(s);


   return (s);
}


/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 *
 * @dest: destination
 * @src: source
 * @n: size
 *
 * Return: pointer to dest
 **/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(dest + i) = *(src + i);

	return (dest);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: old mem
 * @old_size: old_size
 * @new_size: new_size
 *
 * Return: new mem
 **/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *nptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		nptr = malloc(new_size);
		return (nptr);
	}

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}

	nptr = malloc(old_size + (new_size - old_size));

	_memcpy(nptr, ptr, old_size);

	free(ptr);

	return (nptr);
}

/**
 * rot13 - encodes string in rot13 cipher
 * @s: string
 *
 * Return: pointer to string
 **/
char *rot13(char *s)
{

	int i, j, b;
	char *a2;
	char *a1;

	a1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	a2 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		b = 1;
		for (j = 0; a1[j] != '\0' && b; j++)
		{
			if (s[i] == a1[j])
			{
				s[i] = a2[j];
				b = 0;
			}
		}
	}
	return (s);
}
