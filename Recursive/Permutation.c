#include <stdio.h>

int count = 0;

void swap(char *d, int a, int b)
{
	int tmp = d[a];
	d[a] = d[b];
	d[b] = tmp;
}

void perm(char *d, int start, int end)
{
	int i, tmp;
	if(start == end)
	{
		for(i = 0; i <= end; i++)
		{
			if(i == end)
			{
				printf("%c", d[i]);
			}else
			{
				printf("%c, ", d[i]);
			}
		}
		count++;
		printf("\n");
	}
	else
	{
		for(i = start; i <= end; i++)
		{
			swap(d, start, i);
			perm(d, start + 1, end);
			swap(d, start, i);
		}
	}
}

int main(void)
{
	int i,  d_len;
	printf("enter size of permutation(int): ");
	scanf("%d", &d_len);
	char d[d_len];
	printf("the permutation of input number is: ");
	scanf("%s", &d[i]);	
	printf("the result is: \n");
	perm(d, 0, d_len - 1);	
	printf("total number of permutation is: %d\n", count);
	return 0;
}
