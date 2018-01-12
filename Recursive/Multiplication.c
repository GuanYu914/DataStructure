#include <stdio.h>

// according to this furmula "a * b = a * (b - 1) + a"

int mul(int a, int b)
{
	if(b == 1) return a;
	else
		return mul(a, b - 1) + a;
}

int main(void)
{
	int num1 = 0, num2 = 0;
	printf("what is two number you want to multiple? ");
	scanf("%d %d", &num1, &num2);
	printf("the result is: %d\n", mul(num1, num2));
	return 0;
}
