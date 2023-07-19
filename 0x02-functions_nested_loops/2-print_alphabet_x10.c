#include "main.h"

/**
 * main - check the code.
 * print_alphabet_x10 - function that prints 10 times the alphabet,
 * in lowercase, followed by a new line.
 * Return: Always 0.
 */
void print_alphabet_x10(void)
{
	int a;
	
	int b;

	for (b = 1; a <= 10; a++)
	{
		for (b = 97; b <= 122; b++)
		{
			_putchar(b);
		}
		_putchar('\n');
	}
}
