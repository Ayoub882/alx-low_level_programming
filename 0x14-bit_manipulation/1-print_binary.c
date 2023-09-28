#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int shift;
	int flag = 0;

	if (n == 0)
	{
		_putchar('0');
	}


	for (shift = sizeof(unsigned long int) * 8 - 1; shift >= 0; shift--)
	{
		unsigned long int bit = (n >> shift) & 1;

		if (bit == 1)
		{
			flag = 1;
			_putchar('1');
		}
		else if (flag == 1)
		{
			_putchar('0');
		}
	}
}

