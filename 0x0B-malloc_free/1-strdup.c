#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string,
 * or NULL if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *dup_str;
	unsigned int length = 0;
	unsigned int i;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	dup_str = (char *)malloc((length + 1) * sizeof(char));
	if (dup_str == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
	{
		dup_str[i] = str[i];
	}

	return (dup_str);
}
