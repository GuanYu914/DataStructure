#include <stdio.h>
#include <stdbool.h>
#define MAX_DEGREE 10 

// implement with array data structure 

void initArr(int *p)
{
	int i = 0;
	for(i = 0; i < MAX_DEGREE+1; i++)
	{
		*(p+i) = 0;
	}
}

bool isZero(int *p)
{	
	int i = 0;
	for(i = 0; i < MAX_DEGREE+1; i++)
	{
		if(*(p+i) != 0) {return false;}
	}
	return true;	
}

int lead_Exp(int *p)
{
	int i = 0, tmp_max = -1e9, tmp_max_index = 0;
	for(i = MAX_DEGREE; i > 0; i--)
	{
		if(*(p+i) != 0)
		{
			return i;	
		}
	}
}
int compare(int exp_a, int exp_b)
{
	if(exp_a < exp_b)
	{
		return -1;
	}
	if(exp_a == exp_b)
	{
		return 0;
	}
	if(exp_a > exp_b)
	{	
		return 1;
	}
}

int coef(int *p, int lead_index)
{
	return *(p+lead_index);
}

void attach(int *dest, int coef, int exp)
{
	*(dest+exp) = coef;
}

void polyRemove(int *p, int index)
{
	*(p+index) = 0;
}

void polyAdd(int *pdest, int *pa, int *pb)
{
	int sum = 0;
	while(!isZero(pa) && !isZero(pb))
	{
		switch(compare(lead_Exp(pa), lead_Exp(pb)))
		{
			case -1:
				attach(pdest, coef(pb, lead_Exp(pb)), lead_Exp(pb));	
				polyRemove(pb, lead_Exp(pb));	
				break;
			case 0:
				sum = coef(pa, lead_Exp(pa)) + coef(pb, lead_Exp(pb));
				if(sum)
				{
					attach(pdest, sum, lead_Exp(pa));
					polyRemove(pa, lead_Exp(pa));
					polyRemove(pb, lead_Exp(pb));
				}
				break;
			case 1:
				attach(pdest, coef(pa, lead_Exp(pa)), lead_Exp(pa));	
				polyRemove(pa, lead_Exp(pa));	
				break;
		}			
	}
}

void polyDisplay(int *p)
{
	int i = 0;
	for(i = 0; i < MAX_DEGREE + 1; i++)
	{
		printf("x^%d ", i);
	}
	printf("\n");
	for(i = 0; i < MAX_DEGREE + 1; i++)
	{
		printf("%d   ", *(p+i));
	}
	printf("\n");
}

int main(void)
{
	// assign poly_A, poly_B
	int poly_A[MAX_DEGREE+1];
	int poly_B[MAX_DEGREE+1];
	int result[MAX_DEGREE+1];
	initArr(poly_A);
	initArr(poly_B);
	initArr(result);
	// A(x) = 10x^6 + 4x^5 + 4x^2 + 7x + 1	
	poly_A[0] = 1;
	poly_A[1] = 7;
	poly_A[2] = 4;
	poly_A[5] = 4;
	poly_A[6] = 10;
	printf("Polynomial A is: \n");
	polyDisplay(poly_A);
	// B(x) = 7x^7 + 2x^5 + 3 
	poly_B[0] = 3;
	poly_B[5] = 2;
	poly_B[7] = 7;
	printf("Polynomial B is: \n");
	polyDisplay(poly_B);
	polyAdd(result, poly_A, poly_B);
	polyDisplay(result);
	return 0;
}
