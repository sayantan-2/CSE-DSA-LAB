#include <stdio.h>

void printMatrix(int matrix[][3], int row, int col)
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
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("original matrix:\n");
    printMatrix(matrix, 3, 3);

    printf("enter the rows you want to interchange:\n");
    int r1, r2;
    scanf("%d", &r1);
    scanf("%d", &r2);

    int temp[3];
    for (int i = 0; i < 3; i++)
    {
        temp[i] = matrix[r1 - 1][i];
        matrix[r1 - 1][i] = matrix[r2 - 1][i];
        matrix[r2 - 1][i] = temp[i];
    }

    printf("after:\n");
    printMatrix(matrix, 3, 3);

    return 0;
}