#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * string_nconcat - Concatenates two strings with the first n bytes of s2.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of bytes from s2 to concatenate.
 *
 * Return: Pointer to the concatenated string, or NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len_s2 = strlen(s2);
	unsigned int len_s1 = strlen(s1);
	unsigned int total_length = len_s1 + n + 1;
	unsigned int i, j;
	char *result;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (n >= len_s2)
		n = len_s2;

	result = (char *)malloc(total_length);
		if (result == NULL)
			return (NULL);

		for (i = 0; i < len_s1; i++)
			result[i] = s1[i];

		for (j = 0; j < n; j++)
			result[i + j] = s2[j];
		result[i + j] = '\0';

		return (result);
}
