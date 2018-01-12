#include <stdio.h>

// the range of int type is from -2147483648 to 2147483647

int fact(int n)
{
	if(n == 0 || n== 1) return 1;
	else
		return n*fact(n-1);
}

int main(void)
{
	int val = 0;
	printf("what is value of factorial? ");
	scanf("%d", &val);
	printf("the factorial of %d is %d\n", val, fact(val));
	return 0;
}
