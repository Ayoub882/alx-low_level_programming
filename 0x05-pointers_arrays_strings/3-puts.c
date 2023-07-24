#include <stdio.h>

/**
 * _puts - Prints a string followed by a new line to stdout.
 * @str: Pointer to a string to be printed.
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
	putchar('\n');
}

