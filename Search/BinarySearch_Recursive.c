#include <stdio.h>

int BinarySearch(int sorted[], int search, int left, int right)
{
	if(left <= right)
	{
		int middle = (left + right) / 2;
		if(compare(sorted[middle], search) == -1)
			return BinarySearch(sorted, search, middle + 1, right);
		if(compare(sorted[middle], search) == 0)
			return sorted[middle];
		if(compare(sorted[middle], search) == 1)
			return BinarySearch(sorted, search, left, middle - 1);		
	}else
	{
		return -1;
	}
}

int compare(int sorted_num, int search_num)
{
	if(sorted_num < search_num)
		return -1;
	if(sorted_num == search_num)
		return 0;
	if(sorted_num > search_num)
		return 1;
}

int main(void)
{
	int i, len = 0, search_num = 0, index = 0;
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
	if(BinarySearch(data, search_num, 0, len - 1) != -1)
	{
		printf("%d is found.\n.", search_num);
	}else
	{
		printf("%d is not found.\n", search_num);
	}
	return 0;
}
