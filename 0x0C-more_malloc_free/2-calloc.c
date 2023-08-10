#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _calloc - Allocates memory for an array and initializes to zero.
 * @nmemb: Number of elements in the array.
 * @size: Size of each element.
 *
 * Return: Pointer to the allocated memory, or NULL on failure.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *allocated_memory;
	char *ptr;
	unsigned int total_size;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	allocated_memory = malloc(nmemb * size);

	if (allocated_memory == NULL)
		return (NULL);

	ptr = (char *)allocated_memory;
	total_size = nmemb * size;

	for (i = 0; i < total_size; i++)
		ptr[i] = 0;

	return (allocated_memory);
}
