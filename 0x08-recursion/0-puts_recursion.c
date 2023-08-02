#include <stdio.h>

/**
 * _puts_recursion - Prints a string followed by a new line using recursion.
 * @s: Pointer to the input string to be printed.
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		putchar('\n'); /* Print newline when the end of the string is reached */
		return;
	}

	putchar(*s); /* Print the current character */
	/* Call the function recursively with the next character */
	_puts_recursion(s + 1);
}

