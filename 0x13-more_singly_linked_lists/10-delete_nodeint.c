#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at
 * a given index in a listint_t linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 * @index: The index of the node that should be deleted. Index starts at 0.
 *
 * Return: 1 if the deletion succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev_node = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	temp = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (temp != NULL && i < index)
	{
		prev_node = temp;
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
		return (-1);

	prev_node->next = temp->next;
	free(temp);

	return (1);
}

