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

	while (head != NULL)
	{
		char buffer[20];
		int len = snprintf(buffer, sizeof(buffer), "%d");
		write(STDOUT_FILENO, "[", 1);
		write(STDOUT_FILENO, (void *)head, sizeof(void *));
		write(STDOUT_FILENO, "] ", 2);
		write(STDOUT_FILENO, buffer, len);
		write(STDOUT_FILENO, "\n", 1);
		count++;

		if (head <= head->next)
		{
			write(STDERR_FILENO, "-> [", 4);
			write(STDERR_FILENO, (void *)head->next, sizeof(void *));
			write(STDERR_FILENO, "] ", 2);
			len = snprintf(buffer, sizeof(buffer), "%d", head->next->n);
			write(STDERR_FILENO, buffer, len);
			write(STDERR_FILENO, "\n", 1);
			exit(98);
		}

		head = head->next;
	}

	return count;
}

