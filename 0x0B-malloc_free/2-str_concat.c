#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
unsigned int _strlen(char *s)
{
	unsigned int length = 0;

	while (s[length] != '\0')
		length++;

	return (length);
}

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Pointer to the concatenated string, or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int len1, len2, i, j;
	char *concatenated;

	len1 = (s1 != NULL) ? _strlen(s1) : 0;
	len2 = (s2 != NULL) ? _strlen(s2) : 0;

	concatenated = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (concatenated == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concatenated[i] = s1[i];

	for (j = 0; j < len2; j++)
		concatenated[i + j] = s2[j];

	concatenated[i + j] = '\0';

	return (concatenated);
}
