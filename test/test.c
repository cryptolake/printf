#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void) {
  int len;
  int len2;
/*   unsigned int ui; */
/*   void *addr;
 */
  len = _printf("Let's try to printf a simple sentence.\n");
  len2 = printf("Let's try to printf a simple sentence.\n");
  /* ui = (unsigned int)INT_MAX + 1024; */
  /* addr = (void *)0x7ffe637541f0; */
  _printf("Length:[%d, %i]\n", len, len);
  printf("Length:[%d, %i]\n", len2, len2);
  _printf("Negative:[%d]\n", -762534);
  printf("Negative:[%d]\n", -762534);
 /*  _printf("Unsigned:[%u]\n", ui);
  printf("Unsigned:[%u]\n", ui);
  _printf("Unsigned octal:[%o]\n", ui);
  printf("Unsigned octal:[%o]\n", ui);
  _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
  printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui); */
  _printf("Character:[%c]\n", 'H');
  printf("Character:[%c]\n", 'H');
  _printf("String:[%s]\n", "I am a string !");
  printf("String:[%s]\n", "I am a string !");
 /*  _printf("Address:[%p]\n", addr);
  printf("Address:[%p]\n", addr); */
  len = _printf("Percent:[%%]\n");
  len2 = printf("Percent:[%%]\n");
  _printf("Len:[%d]\n", len);
  printf("Len:[%d]\n", len2);

  _printf("");
  printf("");

  _printf("NULL = %s\n", NULL); 
  printf("NULL = %s\n", NULL);

  printf("test %%%d%d%%\n",5,6);
  _printf("test %%%d%d%%\n",5,6);
  
  printf("test %%%i%%%d%%%d%%\n",5,6,7);
  _printf("test %%%i%%%d%%%d%%\n",5,6,7);

  printf("test %%%i%%%d%%%d%%%r\n",5,6,7);
  _printf("test %%%i%%%d%%%d%%%r\n",5,6,7);

  printf("%d%d%%%r%%%d%r%i",2323,333,55555,234);
  putchar('\n');
  _printf("%d%d%%%r%%%d%r%i",2323,333,55555,234);
  putchar('\n');

  len = printf("%");
    putchar('\n');

  printf("len when %%= %d\n",len);

  len = _printf("%");
    putchar('\n');

  _printf("len when %% = %d\n",len);

 len = printf(NULL);
   putchar('\n');

 printf("len when NULL= %d\n", len);

 len = _printf(NULL);
   putchar('\n');

 _printf("len when NULL= %d\n", len);


 len = _printf("Lets print binary!\n");
 _printf("decimal: %i binary: %b\n", len, len);

 _printf("decimal: %i binary: %b\n", 2000, 2000);
 _printf("decimal: %i binary: %b\n", 1952, 1952);
 _printf("decimal: %i binary: %b\n", 999999, 999999);
 

/*   _printf("Unknown:[%r]\n");
 */  /* printf("Unknown:[%r]\n"); */
  return (0);
}
