#include <stdio.h>

int sum(int n)
{
	if(n == 1)
	{
		return 1;
	}else
	{
		return n + sum(n - 1);
	}
}

int main(void)
{
	int d_sum = 0;
	printf("input the number what you want to summation: ");
	scanf("%d", &d_sum);
	printf("the summation of %d is %d.\n", d_sum, sum(d_sum));
}
