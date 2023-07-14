#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (indicating successful execution)
 */
int main(void)
{
	printf("Size of a char: %d byte(s)\n", sizeof(char));
	printf("Soze of an int: %d byte(s)\n", sizeof(int));
	printf("Soze of a long int: %d byte(s)\n", sizeof(long int));
	printf("Soze of a long long int: %d byte(s)\n", sizeof(long long int));
	printf("Size of a float: %d byte(s)\n", sizeof(float));
	return (0);
}
