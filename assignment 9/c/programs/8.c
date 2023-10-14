#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void groupElementsByFirstOccurrence(int arr[], int size)
{
    // Create a dictionary to store the first occurrence index of each element
    int *firstOccurrence = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        firstOccurrence[i] = -1; // Initialize with -1 to indicate no occurrence yet
    }

    // Create a counter for the group numbers
    int groupCounter = 0;

    for (int i = 0; i < size; i++)
    {
        if (firstOccurrence[arr[i]] == -1)
        {
            // This element is seen for the first time
            firstOccurrence[arr[i]] = groupCounter++;
            printf("Group %d: %d", firstOccurrence[arr[i]], arr[i]);
        }
        else
        {
            // This element has been seen before
            printf(" (Group %d)", firstOccurrence[arr[i]]);
        }

        printf("\n");
    }

    free(firstOccurrence);
}

int main()
{
    int arr[] = {4, 2, 4, 1, 6, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Grouped elements based on their first occurrence:\n");
    groupElementsByFirstOccurrence(arr, size);

    return 0;
}
