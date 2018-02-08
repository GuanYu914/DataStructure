#include <stdio.h>
#include <stdlib.h>

void mt_display(int **arr, int r, int c)
{
	int i, j;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("%d\t", *(*(arr + i) + j));
		}
		printf("\n");
	}
}

void mt_read(int **arr, int r, int c)
{
	int i, j;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			scanf("%d", (*(arr + i) + j));
		}
	}
}

void mt_mult(int **a1, int **a2, int **result, int a1_r, int a1_c, int a2_r, int a2_c)
{
	int n, i, j, k, temp_sum = 0;;
		
	// n is a1_c or a2_r
	n = a1_c;
	for(i = 0; i < a1_r; i++)
	{
		for(j = 0; j < a2_c; j++)
		{
			for(k = 0; k < n; k++)
			{
				temp_sum += (*(*(a1 + i) + k)) * (*(*(a2 + k) + j));
				//temp_sum += a1[i][k] * a2[k][j];
			}
			*(*(result + i) + j) = temp_sum;
			//result[i][j] = temp_sum
			temp_sum = 0;
		}
	}
}

int main(void)
{
	int arr1_row, arr1_col, arr2_row, arr2_col;

	printf("Enter the row of matrix_1: \n");
	scanf("%d", &arr1_row);
	printf("Enter the col of matrix_1: \n");
	scanf("%d", &arr1_col);
	printf("Enter the row of matrix_2: \n");
	scanf("%d", &arr2_row);
	printf("Enter the col of matrix_2: \n");
	scanf("%d", &arr2_col);
	
	int **arr1, **arr2, **arr_result;
	int i, j;

	arr1 = malloc(arr1_row * sizeof(*arr1));
	arr2 = malloc(arr2_row * sizeof(*arr1));

	for(i = 0; i < arr1_row; i++)
	{
		arr1[i] = malloc(arr1_col * sizeof(*arr1[i]));
	}
	
	printf("Please enter matrix A by %d*%d: \n", arr1_row, arr1_col);
	mt_read(arr1, arr1_row, arr1_col);
	printf("Display the elements of matrix A: \n");
	mt_display(arr1, arr1_row, arr1_col);	
	
	for(i = 0; i < arr2_row; i++)
	{
		arr2[i] = malloc(arr2_col * sizeof(*arr2[i]));
	}
	
	printf("Please enter matrix B by %d*%d: \n", arr2_row, arr2_col);
	mt_read(arr2, arr2_row, arr2_col);
	printf("Display the elements of matrix B: \n");
	mt_display(arr2, arr2_row, arr2_col);	
	
	if(arr1_col != arr2_row)
	{
		printf("Two matrix can't multiply.\n");
		return ;
	}
		
	// initiate result matrix by a1_r*a2_c
	arr_result = malloc(arr1_row * sizeof(*arr_result));

	for(i = 0; i < arr1_row; i++)
	{
		arr_result[i] = malloc(arr2_col * sizeof(*arr_result[i]));
	}

	for(i = 0; i < arr1_row; i++)
	{
		for(j = 0; j < arr2_col; j++)
		{
			*(*(arr_result + i) + j) = 0;
		}
	}
	mt_mult(arr1, arr2, arr_result, arr1_row, arr1_col, arr2_row, arr2_col);
	printf("Display the elements of matrix result: \n");
	mt_display(arr_result, arr1_row, arr2_col);

	free(arr1);
	free(arr2);
	free(arr_result);
	
	return 0;
}
