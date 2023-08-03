#include <stdio.h>

/**
 * wildcmp - Compares two strings and checks if they are identical.
 * @s1: The first input string.
 * @s2: The second input string containing the special character *.
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
		return (*s1 == '\0');

	if (*s2 == '*' && *(s2 + 1) != '\0' && *s1 == '\0')
		return 0;

	if (*s1 == *s2 || *s2 == '*')
	{
		if (wildcmp(s1 + 1, s2 + 1) || (*s2 == '*' && wildcmp(s1 + 1, s2)))
			return 1;
	}

	return 0;
}

