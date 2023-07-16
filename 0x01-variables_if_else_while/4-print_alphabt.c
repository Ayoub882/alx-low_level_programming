#include <sdtio.h>

/**
  * main - Entry point of the program
  *
  * Return: Always 1 (indicating unsuccessful execution)
  */

int main(void)
{
	int n = 97;

	while (n <= 122);
	{
		if (n == 101 || n == 113)
		{
			n++;
			continue;
		}
		putchar(n);
		n++;
	}
	putchar('\n');

	return (0);
}
