#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

// Time Complexity: O(strlen(Text) * strlen(Pattern))

int main(void)
{
	char Text[MAX_LENGTH] = "";
	char Pattern[MAX_LENGTH] = "";
	int i, j, fail_flg = 1;	

	printf("Enter the Text: ");
	// read string with space character
	scanf("%[^\n]%*c", Text);
	printf("Enter the pattern you wnat to compare: ");
	scanf("%[^\n]%*c", Pattern);

	// '\0' is null character representation
	for(i = 0; i < strlen(Text); i++)
	{
		for(j = 0; Text[i+j] != '\0' && Pattern[j] != '\0' && Text[i+j] == Pattern[j]; j++)
		{
			if(j == strlen(Pattern) - 1)
			{
				printf("The specific Pattern in the text from %d index exactly.\n", i+1);
				fail_flg = 0;
				break;
			}
		}
	}
	if(fail_flg)
	{
		printf("The specific Pattern is not in the text.\n");
	}

	return 0;
}
