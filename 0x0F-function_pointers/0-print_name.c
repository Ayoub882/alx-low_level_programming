#include <stdio.h>

/**
 * print_name - Prints a name using a given function
 * @name: The name to print
 * @f: The function to use for printing
 *
 * Return: Nothing (void)
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}

