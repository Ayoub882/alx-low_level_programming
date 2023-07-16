#include <stdio.h>

/**
  * main - Entry point of the program
  *
  * Return: Always 1 (indicating unsuccessful execution)
  */

int main(void)
{
	int n = 122;

	while (n >= 97)
	{
		putchar(n);
		n--;
	}
	putchar('\n');
	return (0);
}
