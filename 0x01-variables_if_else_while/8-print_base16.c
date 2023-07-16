#include <stdio.h>

/**
  * main - Entry point of the program
  *
  * Return: Always 1 (indicating unsuccessful execution)
  */

int main(void)
{
	int n;
	int m;

	for (n = 48; n <= 57; n++)
	{
		putchar(n);
	}
	for (m = 97; m <= 102; m++)
	{
		putchar(m);
	}
	putchar('\n');
	return (0);
}
