#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

void prefix(char *p, int *f)
{
	f[0] = 0;
	int i = 1, j = 0;
	int m = strlen(p);
	
	// prefix(failure) function calculation	
	while(i < m)
	{
		if(p[i] == p[j])
		{
			f[i] = j + 1;
			i++;
			j++;
		}
		else if(j > 0)
		{
			j = f[j - 1];
		}
		else
		{
			f[i] = 0;
			i++;
		}
	}
}

int main(void)
{
	int i;
	char p[MAX_LENGTH] = "";

	printf("Enter the pattern: ");
	scanf("%[^\n]%*c", p);
	int ff[strlen(p)];
	prefix(p, ff);

	printf("char:  ");
	for(i = 0; i < strlen(p); i++)
		printf("%c ", p[i]);
	
	printf("\nvalue: ");
	for(i = 0; i < sizeof(ff)/sizeof(ff[0]); i++)
		printf("%d ", ff[i]);
	printf("\n");

	return 0;
}
