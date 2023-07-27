#include <stdio.h>

/**
 * rot13 - Encodes a string using ROT13.
 * @str: Pointer to the string to be encoded.
 * Return: Pointer to the encoded string.
 */
char *rot13(char *str)
{
	int i;
	int j;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13_alpha = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; alpha[j]; j++)
		{
			if (str[i] == alpha[j])
			{
				str[i] = rot13_alpha[j];
				break;
			}
		}
	}
	return (str);
}

