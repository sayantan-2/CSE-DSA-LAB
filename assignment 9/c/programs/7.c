#include <stdio.h>
#include <stdlib.h>

void findPairsWithDifference(int arr[], int size, int targetDifference)
{
    // Create a hash table to store elements
    int *hashTable = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        // Calculate the complement needed to achieve the target difference
        int complement = arr[i] - targetDifference;

        // Check if the complement exists in the hash table
        if (complement >= 0 && hashTable[complement] == 1)
        {
            printf("Pair with difference %d found: (%d, %d)\n", targetDifference, complement, arr[i]);
        }

        // Add the current element to the hash table
        hashTable[arr[i]] = 1;
    }

    free(hashTable);
}

int main()
{
    int arr[] = {4, 7, 1, 2, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetDifference = 2;

    findPairsWithDifference(arr, size, targetDifference);

    return 0;
}
