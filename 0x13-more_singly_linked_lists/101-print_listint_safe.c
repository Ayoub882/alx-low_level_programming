#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <unistd.h>

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: Pointer to the head of the linked list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *slow = head, *fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		count++;

		printf("[%p] %d\n", (void *)slow, slow->n);

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				count++;
				printf("[%p] %d\n", (void *)slow, slow->n);
				slow = slow->next;
				fast = fast->next;
			}

			printf("[%p] %d\n", (void *)slow, slow->n);
			exit(98);
		}
	}

	return (count);
}

