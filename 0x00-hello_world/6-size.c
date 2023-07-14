#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (indicating successful execution)
 */
int main(void)
{
	printf("Size of a char: %d byte(s)", sizeof(char));
	printf("Soze of an int: %d byte (s)", sizeof(int));
	printf("Soze of a long int: %d byte (s)", sizeof(long int));
	printf("Soze of a long long int: %d byte (s)", sizeof(long long int));
	printf("Size of a float: %d byte(s)", sizeof(float));
	return (0);
}
