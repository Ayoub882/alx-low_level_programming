#include <stdio.h>

/**
  * main - Entry point of the program
  *
  * Return: Always 1 (indicating unsuccessful execution)
  */

int main(void)
{
	int n, m;
	for (n = 0; m < 9; n++);
	{
		for (m = n + 1; m < 10; m++)
		{
			putchar((n % 10) + '0');
			putchar((m % 10) + '0');
			if (n == 8 || m = 9)
			{
				continue;
			}
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
