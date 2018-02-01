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

        // Print OriginArr
        printf("The Origin Matrix: \n");
        for(i = 0; i < 4; i++)
        {
                for(j = 0; j < 5; j++)
                {
                        printf("%d ", OriginArr[i][j]);
                }
                printf("\n");
        }

		// Init TransPosArr
		int TransPosArr[5][4];
		for(i = 0; i < 5; i++)
		{
			for(j = 0; j < 4; j++)
			{
				TransPosArr[i][j] = 0;
			}
		}

		// Transpose the OringinArr 		
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 5; j++)
			{
				if(OriginArr[i][j])
				{
					TransPosArr[j][i] = OriginArr[i][j];
				}
			}
		}
		
        // Print TransPosArr
        printf("The TransPosArr Matrix: \n");
        for(i = 0; i < 5; i++)
        {
                for(j = 0; j < 4; j++)
                {
                        printf("%d ", TransPosArr[i][j]);
                }
                printf("\n");
		}
        return 0;
}
