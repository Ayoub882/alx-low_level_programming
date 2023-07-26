#include <stdio.h>

/**
* leet - Encodes a string into 1337.
* @str: Pointer to the string to be encoded.
* Return: Pointer to the encoded string.
*/
char *leet(char *str)
{
	int i;
	int j;

	char *leet_chars = "aAeEoOtTlL";
	char *leet_replacements = "4433007711";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; leet_chars[j]; j++)
		{
			if (str[i] == leet_chars[j])
			{
				str[i] = leet_replacements[j];
				break;
			}
		}
	}

	return (str);
}
