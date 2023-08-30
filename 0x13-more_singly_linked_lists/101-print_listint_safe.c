#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0, loop_detected = 0;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		count++;

		printf("[%p] %d\n", (void *)slow, slow->n);

		if (slow == fast)
		{
			loop_detected = 1;
			break; /* Loop detected, break the loop */
		}
	}

	if (loop_detected)
	{
		slow = head;
		while (slow != fast)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			slow = slow->next;
			fast = fast->next;
		}
		printf("-> [%p] %d\n", (void *)slow, slow->n);
		exit(98); /* List contains a loop, exit with status 98 */
	}

	return (count);
}

