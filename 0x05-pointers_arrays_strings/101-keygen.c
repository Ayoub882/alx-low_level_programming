#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
  * generate_random_password - Generates a random password.
  * @password: Pointer to the buffer to store the password.
  * @length: The length of the password.
  */
int main(void)
{
	char pass[84];
	int index = 0, sum = 0, diff_half1, diff_half2;
	
	srand(time(0));
	
	while (sum < 2772)

	{
		pass[index] = 33 + rand() % 94;
		sum += pass[index++];
	}
	pass[index] = '\0';

	if (sum != 2772)

	{
		diff_half1 = (sum - 2772) / 2;
		diff_half2 = (sum - 2772) / 2;

		if ((sum - 2772) % 2 != 0)
			diff_half1++;

		for (index = 0; pass[index]; index++)
		{
			if (pass[index] >= (33 + diff_half1))
			{
				pass[index] -= diff_half1;
				break;
			}
		}
		for (index = 0; pass[index]; index++)
		{
			if (pass[index] >= (33 + diff_half2))
			{
				pass[index] -= diff_half2;
				break;
			}
		}
	}
	printf("%s", pass);
	return (0);
}
