#include <stdio.h>

int main()
{
    int matrix[4][5] = {{0, 0, 3, 0, 4}, {0, 0, 5, 7, 0}, {0, 0, 0, 0, 0}, {0, 2, 6, 0, 0}};
    int c = 0;
    int e = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == 0)
            {
                c++;
            }
            e++;
        }
    }

    printf("The matrix is %s a sparse matrix\n", (c > e / 2) ? "" : "not");

    return 0;
}