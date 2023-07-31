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
    int arr[5];
    int e;
    printf("Enter 5 elements of the array:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be deleted: ");
    scanf("%d", &e);
    int length = 5;
    int found = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == e)
        {
            found = 1;
            for (int j = i; j < length - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            length--;
        }
    }
    if (found)
    {
        printf("Element %d deleted from the array.\n", e);
        printf("Updated array: ");
        printarray(arr, length);
    }
    else
    {
        printf("Element %d not found in the array.\n", e);
    }
    return 0;
}