#include <stdio.h>

void printSubarray(int arr[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printSubarraysWithZeroSum(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                printSubarray(arr, i, j);
            }
        }
    }
}

int main()
{
    int arr[] = {4, 2, -3, 1, 6, -1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Subarrays with zero sum:\n");
    printSubarraysWithZeroSum(arr, size);

    return 0;
}
