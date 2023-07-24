/**
 * rev_string - Reverses a string.
 * @s: Pointer to a string to be reversed.
 */
void rev_string(char *s)
{
	int length = 0;
	char *start = s;
	char *end = s;

	/**
	  *Calculate the length of the string
	  */

	while (*end != '\0')
	{
		length++;
		end++;
	}

	end--;
	/**
	  *Move end back to the last character of the string
	  */

	/**
	  *Swap characters from start to end
	  */

	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

