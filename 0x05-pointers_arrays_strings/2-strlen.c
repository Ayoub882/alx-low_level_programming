#include <stdio.h>

/**
 * _strlen - Returns the length of a string.
 * @s: Pointer to a string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int length_of_a_string = 0;

	while (*s != '\0')
	{
		length_of_a_string++;
		s++;
	}

	return (length_of_a_string);
}
