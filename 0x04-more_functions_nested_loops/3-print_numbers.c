#include "main.h"

int _putchar(char c);

/**
 * print_numbers - prints the numbers from 0 to 9, followed by a new line
 */
void print_numbers(void)
{
	char number;

	for (number = '0'; number <= '9'; number++)
	{
		_putchar(number);
	}
	_putchar('\n');
}
