#include <stdio.h>
#include <stdlib.h>

void findMaxSubarrayWithEqualZerosAndOnes(int arr[], int size)
{
    int maxLength = 0;
    int currentCount = 0;
    int endIndex = -1;
    int startIndex = -1;

    int *countDifferences = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            currentCount--;
        }
        else
        {
            currentCount++;
        }
        countDifferences[i] = currentCount;
    }

    // Create a hash table to store the first occurrence of each count difference
    int hashTable[2 * size + 1];
    for (int i = 0; i < 2 * size + 1; i++)
    {
        hashTable[i] = -1;
    }

    for (int i = 0; i < size; i++)
    {
        if (countDifferences[i] == 0)
        {
            maxLength = i + 1;
            endIndex = i;
        }
        else if (hashTable[countDifferences[i] + size] == -1)
        {
            hashTable[countDifferences[i] + size] = i;
        }
        else
        {
            if (i - hashTable[countDifferences[i] + size] > maxLength)
            {
                maxLength = i - hashTable[countDifferences[i] + size];
                startIndex = hashTable[countDifferences[i] + size] + 1;
                endIndex = i;
            }
        }
    }

    if (maxLength > 0)
    {
        printf("Maximum length subarray with equal 0s and 1s is [%d, %d]\n", startIndex, endIndex);
    }
    else
    {
        printf("No subarray with equal 0s and 1s found.\n");
    }

    free(countDifferences);
}

int main()
{
    int arr[] = {0, 1, 0, 1, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    findMaxSubarrayWithEqualZerosAndOnes(arr, size);

    return 0;
}
