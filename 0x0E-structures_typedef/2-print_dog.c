#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints information about a struct dog
 * @d: A pointer to the struct dog
 *
 * Return: Nothing (void)
 */

void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", d->name ? d->name : "(nil)");
		printf("Age: %.6f\n", d->age);
		printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
	}
}

