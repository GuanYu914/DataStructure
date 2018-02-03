#include <stdio.h>
#include <stdlib.h>
#define MAX_STORE 100

// Time complexity: 
// Non-Sparse matrix: O(row * col)  
// Sparse matrix:     O(terms)
// ps. terms = row * col

typedef struct
{
	int row;
	int col;
	int val;
}sparse;

// Used to record the number of non-zero value
int terms = 0;

void sparse_init(sparse a[])
{
	int i;
	for(i = 0; i < MAX_STORE; i++)
	{
		a[i].row = 0;
		a[i].col = 0;
		a[i].val = 0;
	}
}

void sparse_display(sparse a[])
{
	int i;
	printf("Row\t Col\t Val\n");
	for(i = 0; i < MAX_STORE; i++)
	{
		// display non-zero value
		if(a[i].val)
		{
			printf("%d", a[i].row);
			printf("\t %d", a[i].col);
			printf("\t %d\n", a[i].val);
		}
	}
}

void sparse_read(sparse a[], int row, int col)
{
	int i, j, item = 0;
	// recalculate it. 	
	terms = 0;
	
	printf("Enter the sparse matrix by %d*%d: \n", row, col);
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			scanf("%d", &item);
			// store non-zero value
			if(item)
			{
				a[terms].row = i;
				a[terms].col = j;
				a[terms].val = item;
				terms++;
			}
		}
	}				
}

sparse *sparse_fast_transpose(sparse a[], int col)
{
	int i;
	// use two variable to optimize
	int RowSize[col];
	int RowStart[col];
	for(i = 0; i < col; i++)
	{
		RowSize[i]  = 0;
		RowStart[i] = 0;
	}
	sparse *b;
	b = malloc(terms * sizeof(sparse));
	if(terms)
	{
		for(i = 0; i < terms; i++)
		{
			RowSize[a[i].col]++;			
		}

		RowStart[0] = 0;
		for(i = 1; i < col; i++)
		{
			RowStart[i]	= RowStart[i-1] + RowSize[i-1];	
		}
		
		// main code of fast matrix transpose 			
		for(i = 0; i < terms; i++)
		{
			int j = RowStart[a[i].col];
			(b+j) -> row = a[i].col;
			(b+j) -> col = a[i].row;
			(b+j) -> val = a[i].val;
			RowStart[a[i].col]++;
		}
	}
	return b;
}

int main(void)
{
	int sm_row = 0, sm_col = 0;
	printf("Enter the row of sparse matrix: \n");
	scanf("%d", &sm_row);	
	printf("Enter the col of sparse matrix: \n");
	scanf("%d", &sm_col);
	sparse origin[MAX_STORE];
	sparse_init(origin);
	sparse_read(origin, sm_row, sm_col);
	printf("The sparse of origin: \n");
	sparse_display(origin);
	sparse *transpose = sparse_fast_transpose(origin, sm_col);
	printf("The sparse of transpose: \n");
	sparse_display(transpose);
	free(transpose);
	return 0;
}
