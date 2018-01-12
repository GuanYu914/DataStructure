#include <stdio.h>

void print(int *ptr, int rows)
{
	int i;
	printf("Address	   Contents\n");
	for(i = 0; i < rows; i++)
	{
		printf("%u %d\n", ptr+i, *(ptr+i));
	}
	printf("\n");
}

int main(void)
{
	int one[] = {0, 1, 2, 3, 4};
	print(one, 5);
}
