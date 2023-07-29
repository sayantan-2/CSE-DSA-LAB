#include <stdio.h>
int main()
{
    int a = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j < 3; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("%d ", a);
            a++;
        }
        printf("\n");
    }
    return 0;
}