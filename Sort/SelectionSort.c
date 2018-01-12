#include <stdio.h>

void SelectionSort(int data[], int n)
{
	int i, j, min_index;
	for(i = 0; i < n; i++)
	{	
		min_index = i;
		for(j = i+1; j < n; j++)
		{
			if(data[j] < data[min_index])
			{
				min_index = j;
			}
		}
		int tmp = data[i];
		data[i] = data[min_index];
		data[min_index] = tmp;
	}
}

void print(int data[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, len = 0;
	printf("input array size: ");
	scanf("%d", &len);
	int data[len];	
	printf("enter array elements: ");
	for(i = 0; i < len; i++)
	{
		scanf("%d", &data[i]);
	}
	SelectionSort(data, len);
	printf("sorted array is ");
	print(data, len);
	return 0;
}


