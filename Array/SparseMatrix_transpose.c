#include <stdio.h>
#include <stdlib.h>
#define MAX_STORE 100

// Time Complexity:
// Non-Sparse matrix: O(col * terms)
// Sparse matrix    : O(col * col * row)
// ps. terms = col * row

typedef struct
{
	int row;
	int col;
	int val;
}sparse;

// Using global variable to record the non-zero number in matrix
int terms;

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

void sparse_read(sparse a[], int row, int col)
{
	int i, j, item= 0;
	terms = 0;
	printf("Enter a sparse matrix by %d*%d\n", row, col);
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			scanf("%d", &item);
			// record non-zero number
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

sparse* sparse_transpose(sparse a[], int col, int terms)
{
	sparse *b;
	b = malloc(terms * sizeof(sparse));
	int i, j;
	// if matrix is non-zero
	if(terms)
	{
		int k = 0;
		// transpose by columns
		for(i = 0; i < col; i++)
		{
			for(j = 0; j < terms; j++)
			{
				if(a[j].col == i)
				{
					(b+k) -> row = i;
					(b+k) -> col = a[j].row;
					(b+k) -> val = a[j].val;
					k++;
				}
			}	
		}		
	}
	return b;	
}

void sparse_display(sparse a[])
{
	int i;
	printf("Row\t Col\t Val\n");
	for(i = 0; i < MAX_STORE; i++)
	{
		if(a[i].val)
		{
			printf("%d", a[i].row);			
			printf("\t %d", a[i].col);			
			printf("\t %d\n", a[i].val);			
		}
	}
}

int main(void)
{
	int sm_row, sm_col;
	sparse origin[MAX_STORE];
	sparse_init(origin);
	printf("Enter the row of sparse matrix: \n");
	scanf("%d", &sm_row);
	printf("Enter the col of sparse matrix: \n");
	scanf("%d", &sm_col);
	sparse_read(origin, sm_row, sm_col);
	printf("The sparse of origin: \n");
	sparse_display(origin);
	sparse *transpose = sparse_transpose(origin, sm_col, terms);
	printf("The sparse of transpose: \n");
	sparse_display(transpose);
	free(transpose);
	return 0;
}
