#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 * This function can print lists with a loop.
 * You should go through the list only once.
 * If the function fails, exit the program with status 98.
 * Output format: [address] n
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;
	const listint_t *loop_node = NULL;

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		if (current <= loop_node)
		{
			exit(98);
		}

		loop_node = current;
		current = current->next;
	}

	return (count);
}

