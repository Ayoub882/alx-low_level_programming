#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: The argument count.
 * @av: An array of strings containing the arguments.
 *
 * Return: Pointer to the concatenated string, or NULL on failure.
 */
char *argstostr(int ac, char **av)
{
	int total_length = 0, j = 0, i = 0, index;
	char *result;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j])
		{
			total_length++;
			j++;
		}
		total_length++; /* For the newline character*/
	}
	total_length++; /* For the null terminator*/

	result = (char *)malloc(total_length * sizeof(char));
	if (result == NULL)
		return (NULL);

	index = 0;
	for (i = 0; i < ac; i++)
			{
			j = 0;
			while (av[i][j])
			{
				result[index++] = av[i][j];
				j++;
			}
			result[index++] = '\n';
			}
	result[index] = '\0';

	return (result);
}
