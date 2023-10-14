#include <stdio.h>

void findLargestConsecutiveSubarray(int arr[], int size)
{
    int maxLength = 0;  // Length of the largest consecutive subarray
    int startIndex = 0; // Starting index of the largest consecutive subarray
    int endIndex = 0;   // Ending index of the largest consecutive subarray

    int currentLength = 1; // Length of the current consecutive subarray

    for (int i = 1; i < size; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            currentLength++;
        }
        else
        {
            if (currentLength > maxLength)
            {
                maxLength = currentLength;
                startIndex = i - maxLength;
                endIndex = i - 1;
            }
            currentLength = 1;
        }
    }

    // Check if the last subarray is the largest
    if (currentLength > maxLength)
    {
        maxLength = currentLength;
        startIndex = size - maxLength;
        endIndex = size - 1;
    }

    if (maxLength > 0)
    {
        printf("Largest consecutive subarray is [%d, %d]\n", startIndex, endIndex);
    }
    else
    {
        printf("No consecutive subarray found.\n");
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    findLargestConsecutiveSubarray(arr, size);

    return 0;
}
