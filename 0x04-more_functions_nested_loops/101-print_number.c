#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 */
void print_number(int n)
{
	 int is_negative = 0;

	 if (n < 0)
	 {
		 _putchar('-');
		 n = -n;
		 is_negative = 1;
	 }
	 if (n / 10 != 0)
	 {
		 print_number(n / 10);
	 }

	 _putchar((n % 10) + '0');
}

