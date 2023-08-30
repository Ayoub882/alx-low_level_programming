#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h, *temp = NULL;
	size_t count = 0;

	while (current != NULL)
	{
		if (current->next == *h)
		{
			temp = current->next;
			current->next = NULL;
			current = temp;
		}
		else
		{
			temp = current;
			current = current->next;
		}

		free(temp);
		count++;

		if (current == *h)
		{
			free(current);
			*h = NULL;
		}
	}

	return (count);
}

