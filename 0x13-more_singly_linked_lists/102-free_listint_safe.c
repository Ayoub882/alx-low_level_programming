#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: A pointer to a pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 * This function can free lists with a loop.
 * You should go through the list only once.
 * The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current = *h, *next;

	while (current != NULL)
	{
		count++;
		next = current->next;
		free(current);
		current = next;

		/* Detect if a loop exists */
		if (next == *h)
		{
			*h = NULL; /* Set the head to NULL to prevent further access */
			return (count);
		}
	}

	*h = NULL; /* Set the head to NULL */
	return (count);
}

