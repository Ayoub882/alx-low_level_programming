#include <stdio.h>

/**
  * main - Entry point of the program
  *
  * Return: Always 1 (indicating unsuccessful execution)
  */

int main(void)
{
	int a, b;

	for (a = 0; a < 100; a++)
	{
		for (b = i; b < 100; b++)
		{
			int first_num = a / 10;
			int second_num = a % 10;
			int third_num = b / 10;
			int fourth num = b % 10;

			putchar(first_num + '0');
			putchar(second_num + '0');
			putchar(' ');
			putchar(third_num + '0');
			putchar(fourth_num + '0');

			if (a != 99 || b !- 99)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar ('\n');
	return (0);
}
