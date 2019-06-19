#include <stdio.h>
#include <stdlib.h>

void transposeMatrix(int**, int, int);
void allocateMemoryForMatrix(int***, int, int);
void destroyMatrix(int**, int, int);
void printMatrix(int**, int, int);
void swap(int*, int*);

int main()
{
    int     size    = 0;
    int     count   = 0;
    int**   mtr     = NULL;

    printf("Enter matrix size: \n");
    scanf("%d", &size);
    allocateMemoryForMatrix(&mtr, size, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mtr[i][j] = ++count;
        }
    }

    transposeMatrix(mtr, size, size);
    printf("Check algorithm: \n");
    printMatrix(mtr, size, size);
    destroyMatrix(mtr, size, size);

    return 0;
}

void transposeMatrix(int** mtr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            if(i != j)
            {
                swap(&(mtr[i][j]), &(mtr[j][i]));
            }
        }
    }
}

void allocateMemoryForMatrix(int ***mtr, int row, int col)
{
	*mtr = (int **) malloc(sizeof(int *) * row);
	for(int i = 0; i < row; i++)
	{
		(*mtr)[i] = (int *)malloc(sizeof(int) * col);
	}
}

void destroyMatrix(int **mtr, int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		free(mtr[i]);
	}
	free(mtr);
}

void printMatrix(int** mtr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", mtr[i][j]);
        }
        
        printf("\n");
    }
}

void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
