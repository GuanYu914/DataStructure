#include <stdio.h>
#define MAX_STORE 100

typedef struct
{
	int row;
	int col;
	int val;
}sparse;

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
	int i, j, item, terms = 0;
	printf("Enter a sparse matrix by %d*%d\n", row, col);
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			scanf("%d", &item);
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
		sparse_display(origin);	 		
        return 0;
}
