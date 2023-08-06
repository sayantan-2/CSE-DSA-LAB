#include <stdio.h>

void spiral_matrix(int n, int matrix[][n])
{
    int count = 1;
    for (int layer = 0; layer < (n + 1) / 2; layer++)
    {
        for (int i = layer; i < n - layer; i++)
        {
            matrix[layer][i] = count;
            count++;
        }
        for (int i = layer + 1; i < n - layer; i++)
        {
            matrix[i][n - layer - 1] = count;
            count++;
        }
        for (int i = layer + 1; i < n - layer; i++)
        {
            matrix[n - layer - 1][n - i - 1] = count;
            count++;
        }
        for (int i = layer + 1; i < n - layer - 1; i++)
        {
            matrix[n - i - 1][layer] = count;
            count++;
        }
    }
}

int main()
{
    int n = 3;
    int matrix[n][n];

    spiral_matrix(n, matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}