//program to delete ana element from an array
#include <stdio.h>

void printarray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int e;
    printf("enter the element to be deleted:");
    scanf("%d", &e);
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == e)
        {
            for (int j = i; j < 8; j++)
            {
                arr[j] = arr[j + 1];
            }
        }
    }
    printarray(arr,8);
    return 0;
}