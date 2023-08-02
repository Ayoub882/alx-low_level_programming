#include <stdio.h>

/**
 * _strlen_recursion - Returns the length of a string using recursion.
 * @s: Pointer to the input string whose length is to be calculated.
 * Return: Length of the string.
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0); /* Base case: return 0 when the end of the string is reached */

	/* Recursively call the function with the next character */
	return (1 + _strlen_recursion(s + 1));
}

