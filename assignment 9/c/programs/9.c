#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findMinimumIndexOfRepeatingElement(int arr[], int size)
{
    // Create a dictionary to store the index of the first occurrence of each element
    int *firstOccurrence = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        firstOccurrence[i] = -1; // Initialize with -1 to indicate no occurrence yet
    }

    int minIndex = size;

    for (int i = 0; i < size; i++)
    {
        if (firstOccurrence[arr[i]] == -1)
        {
            // This element is seen for the first time
            firstOccurrence[arr[i]] = i;
        }
        else
        {
            // This element has been seen before, update minIndex if needed
            if (firstOccurrence[arr[i]] < minIndex)
            {
                minIndex = firstOccurrence[arr[i]];
            }
        }
    }

    if (minIndex < size)
    {
        printf("Minimum index of a repeating element: %d\n", minIndex);
    }
    else
    {
        printf("No repeating elements found.\n");
    }

    free(firstOccurrence);
}

int main()
{
    int arr[] = {4, 2, 6, 1, 6, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    findMinimumIndexOfRepeatingElement(arr, size);

    return 0;
}
