#include <stddef.h>
#include "lists.h"

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
    size_t node_count = 0;

    while (h != NULL)
    {
        char digit = h->n + '0'; /*Convert integer to character*/
        _putchar(digit); /*Call _putchar to print the character*/
        _putchar('\n'); /*Print newline character*/
        h = h->next;
        node_count++;
    }

    return (node_count);
}

