#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 1 (indicating unsuccessful execution)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0) 
	{
		printf("%d is positif\n",n);
	}
	else if (n == 0)
	{
		 printf("%d is zero\n",n);
	}
	else 
	{
		 printf("%d is negative\n",n);
	}
	return (0);
}
