#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int i;
	int count = 0;
	int is_word = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			if (!is_word)
			{
				count++;
				is_word = 1;
			}
		}
		else
		{
			is_word = 0;
		}
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: Pointer to an array of strings (words), or NULL on failure.
 */
char **strtow(char *str)
{
	int word_count = count_words(str);
	int word_index, word_start, i, j, word_length;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	word_index = 0;
	word_start = -1;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			if (word_start == -1)
				word_start = i;
		}
		else
		{
			if (word_start != -1)
			{
				word_length = i - word_start;
				words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
				if (words[word_index] == NULL)
				{
					for (j = 0; j < word_index; j++)
						free(words[j]);
					free(words);
					return (NULL);
				}

				strncpy(words[word_index], str + word_start, word_length);
				words[word_index][word_length] = '\0';
				word_index++;

				word_start = -1;
			}
		}
	}

	if (word_start != -1)
	{
		word_length = strlen(str) - word_start;
		words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
		if (words[word_index] == NULL)
		{
			for (j = 0; j < word_index; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}

		strncpy(words[word_index], str + word_start, word_length);
		words[word_index][word_length] = '\0';
		word_index++;
	}

	words[word_index] = NULL;

	return (words);
}
