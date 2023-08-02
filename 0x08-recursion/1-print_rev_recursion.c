#include <stdio.h>

/**
 * _print_rev_recursion - Prints a string in reverse using recursion.
 * @s: Pointer to the input string to be printed in reverse.
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
		return; /* Base case: return when the end of the string is reached */

	/* Recursively call the function with the next character */
	_print_rev_recursion(s + 1);
	putchar(*s); /* Print the current character after the recursive call */
}

