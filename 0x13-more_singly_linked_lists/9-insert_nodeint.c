#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at
 * a given position in a listint_t linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 * @idx: The index where the new node should be added. Index starts at 0.
 * @n: The value to add to the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current = *head;
	unsigned int i = 0;

	if (idx == 0)
	{
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL)
			return (NULL);

		new_node->n = n;
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	if (current != NULL)
	{
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL)
			return (NULL);

		new_node->n = n;
		new_node->next = current->next;
		current->next = new_node;
		return (new_node);
	}

	return (NULL);
}

