#include <stdio.h>

int subarrayWithZeroSum(int arr[], int size)
{
    // Create a prefix sum array to store the cumulative sum of elements
    int prefixSum[size];
    prefixSum[0] = arr[0];

    for (int i = 1; i < size; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    // Create a hash table to store prefix sum values
    // If the same prefix sum appears more than once, a subarray with sum 0 exists
    int hashTable[100000] = {0};

    for (int i = 0; i < size; i++)
    {
        if (prefixSum[i] == 0 || hashTable[prefixSum[i]] == 1)
        {
            return 1; // Subarray with sum 0 found
        }
        hashTable[prefixSum[i]] = 1;
    }

    return 0; // No subarray with sum 0 found
}

int main()
{
    int arr[] = {4, 2, -3, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (subarrayWithZeroSum(arr, size))
    {
        printf("Subarray with sum 0 exists.\n");
    }
    else
    {
        printf("Subarray with sum 0 does not exist.\n");
    }

    return 0;
}
