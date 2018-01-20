#include <stdio.h>

int main(void)
{
        int i, j, size = 0;
        int OriginArr[4][5] =
        {
                {0, 0, 3, 0, 4},
                {0, 0, 5, 7, 0},
                {0, 0, 0, 0, 0},
                {0, 2, 6, 1, 0}
        };

        //Print OriginArr
        printf("The Origin Matrix: \n");
        for(i = 0; i < 4; i++)
        {
                for(j = 0; j < 5; j++)
                {
                        printf("%d ", OriginArr[i][j]);
                }
                printf("\n");
        }

        //Get max non-zero number in OriginArr
        for(i = 0; i < 4; i++)
        {
                for(j = 0; j < 5; j ++)
                {
                        if(OriginArr[i][j]){ size++; }
                }
        }

        // Construct a new SparseArr
        // SparseArr[0] -> store row index
        // SparseArr[1] -> store col index
        // SparseArr[2] -> store value
        int SparseArr[3][size];
        for(i = 0; i < 3; i++)
        {
                for(j = 0; j < size; j++)
                {
                        SparseArr[i][j] = 0;
                }
        }

        // Covert OriginArr to SparseArr representation
        int k = 0;
        for(i = 0; i < 4; i ++)
        {
                for(j = 0; j < 5; j++)
                {
                        if(OriginArr[i][j])
                        {
                                SparseArr[0][k] = i;
                                SparseArr[1][k] = j;
                                SparseArr[2][k] = OriginArr[i][j];
                                k++;
                        }
                }
        }

        //Print SparseArr
        printf("The Sparse Matrix: \n");
        for(i = 0; i < 3; i++)
        {
                if(i == 0){ printf("Row: "); }
                if(i == 1){ printf("Col: "); }
                if(i == 2){ printf("Val: "); }

                for(j = 0; j < size; j++)
                {
                        printf("%d ", SparseArr[i][j]);
                }
                printf("\n");
        }

        return 0;
}
