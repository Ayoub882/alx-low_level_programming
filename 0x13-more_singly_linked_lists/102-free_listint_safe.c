#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nodes = 0;
	listint_t *temp;

	if (h == NULL || *h == NULL)
		return (nodes);

	while (*h != NULL)
	{
		nodes++;
		if (*h < (*h)->next)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
		}
		else
		{
			free(*h);
			break;
		}
	}

	*h = NULL;
	return (nodes);
}
