#include "main.h"

/**
 * print_triangle - prints a triangle using the # character
 * @size: The size of the triangle
 */
void print_triangle(int size)
{
	int i, j, space;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= size; i++)
	{
		/**
		  *Print leading spaces
		  */
		for (space = size - i; space > 0; space--)
		{
			_putchar(' ');
		}
		/**
		  *Print the hash symbols
		  */
		for (j = 1; j <= i; j++)
		{
			_putchar('#');
		}

		/*
		   *Move to the next line
		   */
		_putchar('\n');
	}
}

