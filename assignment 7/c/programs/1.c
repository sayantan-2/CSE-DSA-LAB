#include <stdio.h>
int main()
{
    int a = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (a % 2 != 0)
            {
                printf("*");
            }
            else
            {
                printf("#");
            }
            a++;
        }
        printf("\n");
    }

    return 0;
}