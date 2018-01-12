#include <stdio.h>

void BinarySearch(int sorted[], int search, int len)
{
	int low = 0, high = len - 1, mid = 0;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(sorted[mid] > search)
		{
			high = mid - 1;
		}
		if(sorted[mid] < search)
		{
			low = mid + 1;
		}
		if(sorted[mid] == search)
		{
			printf("found data in array index[%d]\n", mid);
			return ;
		}
	}
	printf("data not found\n");
	return ;
}

int main(void)
{
	int i, len = 0, search_num = 0;
	printf("input array size: ");
	scanf("%d", &len);
	int data[len];
	printf("enter sorted array(from smallest to largest): ");
	
	for(i = 0; i < len; i++)
	{
		scanf("%d", &data[i]);
	}

	printf("enter you want to search number: ");
	scanf("%d", &search_num);
	BinarySearch(data, search_num, len);
	
	return 0;
}
