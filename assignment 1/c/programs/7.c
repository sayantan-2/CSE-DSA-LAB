#include <stdio.h>

void deleteDuplicates(int array[], int *size)
{
    for (int i = 0; i < *size; i++)
    {
        for (int j = i + 1; j < *size; j++)
        {
            if (array[i] == array[j])
            {
                // Shift elements to the left to remove the duplicate
                for (int k = j; k < (*size) - 1; k++)
                {
                    array[k] = array[k + 1];
                }
                (*size)--;
                j--; // Re-check the current index, as it has a new element after the shift
            }
        }
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[100];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Original array: ");
    printArray(array, size);

    deleteDuplicates(array, &size);

    printf("Array with duplicates removed: ");
    printArray(array, size);

    return 0;
}