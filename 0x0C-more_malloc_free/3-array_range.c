#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * array_range - Creates an array of integers from min to max.
 * @min: The starting value.
 * @max: The ending value.
 *
 * Return: Pointer to the newly created array, or NULL on failure.
 */
int *array_range(int min, int max)
{
	int size;
	int *new_array;
	int i;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	new_array = (int *)malloc(size * sizeof(int));

	if (new_array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		new_array[i] = min + i;

	return (new_array);
}
