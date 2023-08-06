#include <stdio.h>

void printMatrix(int matrix[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    printf("old matrix:\n");
    printMatrix(mat, 4, 4);

    int mat_new[4][4];
    int n = 0;
    for (int i = 4; i > 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            mat_new[j][i - 1] = mat[n][j];
        }
        n++;
    }

    printf("new matrix:\n");
    printMatrix(mat_new, 4, 4);

    return 0;
}