#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <unistd.h>

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
	const listint_t *tortoise = head, *hare = head;
	int len;
	char buffer[20];

	while (hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		len = snprintf(buffer, sizeof(buffer), "%d", tortoise->n);

		write(STDOUT_FILENO, "[", 1);
		write(STDOUT_FILENO, (void *)&tortoise, sizeof(void *));
		write(STDOUT_FILENO, "] ", 2);
		write(STDOUT_FILENO, buffer, len);
		write(STDOUT_FILENO, "\n", 1);
		count++;

		if (tortoise == hare)
		{
			len = snprintf(buffer, sizeof(buffer), "%d", hare->n);
			write(STDOUT_FILENO, "-> [", 4);
			write(STDOUT_FILENO, (void *)&hare, sizeof(void *));
			write(STDOUT_FILENO, "] ", 2);
			write(STDOUT_FILENO, buffer, len);
			write(STDOUT_FILENO, "\n", 1);
			exit(98);
		}
	}

	return (count);
}

