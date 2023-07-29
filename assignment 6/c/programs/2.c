#include <stdio.h>
int main()
{
    int i, j, k;
    for (i = 0; i < 4; i++)
    {
        for (j = i; j < 3; j++)
        {
            printf(" ");
        }
        for (k = 0; k < i + 1; k++)
        {
            printf("%c ", 65 + i);
        }
        printf("\n");
    }
    return 0;
}