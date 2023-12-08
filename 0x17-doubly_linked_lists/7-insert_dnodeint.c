#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: pointer to the pointer to the head of the list.
 * @idx: index of the list where the new node should be added.
 * @n: data for the new node.
 * Return: the address of the new node, or NULL if it failed.
 **/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int i = 0;

	if (!h)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = *h;
		new_node->prev = NULL;
		if (*h)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}
	current = *h;
	while (current && i < idx - 1)
	{
		current = current->next;
		i++;
	}
	if (!current)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = current->next;
	new_node->prev = current;
	if (current->next)
		current->next->prev = new_node;
	current->next = new_node;
	return (new_node);
}
