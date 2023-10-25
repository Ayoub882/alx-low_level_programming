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
	int loop_detected = 0;

	while (head != NULL)
	{
		char buffer[20];
		int len = snprintf(buffer, sizeof(buffer), "%d");

		write(STDOUT_FILENO, "[", 1);
		write(STDOUT_FILENO, (void *)&head, sizeof(void *));
		write(STDOUT_FILENO, "] ", 2);
		write(STDOUT_FILENO, buffer, len);
		write(STDOUT_FILENO, "\n", 1);

		count++;

		if (loop_detected == 0 && head <= head->next)
		{
			loop_detected = 1;
			fprintf(stderr, "-> [%p] %d\n", (void *)head->next, head->next->n);
		}

		head = head->next;
	}

	if (loop_detected == 1)
	{
		exit(98);
	}

	return (count);
}

