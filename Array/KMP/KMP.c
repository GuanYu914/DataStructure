#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

// Time complexity is O(strlen(T) + strlen(P))

void prefix(char *p, int *f)
{
	f[0] = 0;
	int i = 1, j = 0;
	int m = strlen(p);
	// failure function calculation
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

void kmp(char *t, char *p)
{
	int n = strlen(t);
	int m = strlen(p);
	int flag = 0;	
	int f[m];
	prefix(p, f);

	int i = 0, j = 0;
	// kmp with failure function
	while(i < n)
	{
		if(t[i] == p[j])
		{
			if(j == m - 1)
			{
				// (i - j) is the pattern begin index, then from the index 1
				printf("The specific Pattern in the text from %d index exactly.\n", (i - j) + 1);
				i++;
				flag = 1;
			}
			else
			{
				i++;
				j++;
			}
		}
		else
		{
			if(j > 0)
			{
				j = f[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	if(!flag)
	{
		printf("The specific Pattern is not in the text.\n");
	}
}

int main(void)
{
	char T[MAX_LENGTH] = "";
	char P[MAX_LENGTH] = "";
	
	printf("Enter the Text: ");
	scanf("%[^\n]%*c", T);
	printf("Enter the Pattern: ");
	scanf("%[^\n]%*c", P);
	kmp(T, P);

	return 0;
}
