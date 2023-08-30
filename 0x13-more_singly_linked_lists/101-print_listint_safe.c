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
    const listint_t *current = head, *loop_node = head;
    size_t count = 0;

    while (current != NULL)
    {
        printf("[%p] %d\n", (void *)current, current->n);

        if (current->next == loop_node && count > 0)
        {
            printf("-> [%p] %d\n", (void *)loop_node, loop_node->n);
            break; /* List contains a loop, break the loop */
        }

        count++;
        current = current->next;

        if (current == loop_node)
        {
            printf("-> [%p] %d\n", (void *)loop_node, loop_node->n);
            exit(98); /* List contains a loop, exit with status 98 */
        }

        if (count % 2 == 0 && loop_node != NULL)
            loop_node = loop_node->next;
    }

    return count;
}

