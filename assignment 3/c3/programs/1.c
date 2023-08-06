#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    int matrix[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int s = 0;
    for (int i = 0; i < m; i++)
    {
        s += matrix[i][i];
    }
    printf("sum of principal diagonal: %d\n", s);

    s = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == m - 1)
            {
                s += matrix[i][j];
            }
        }
    }
    printf("sum of anti diagonal: %d\n", s);

    return 0;
}