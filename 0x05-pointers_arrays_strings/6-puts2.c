#include <stdio.h>

/**
 * puts2 - Prints every other character of a string,
 * starting with the first character.
 * @str: Pointer to a string.
 */
void puts2(char *str)
{
	int dex;
	int index = 0;

	while (str[index] != '\0')
	{
		index += 2;
	}
	for (dex = 0, dex < index, dex += 2)
	{
		putchar(str[dex]);
	}

	putchar('\n');
}
