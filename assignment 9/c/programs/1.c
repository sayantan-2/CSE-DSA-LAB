#include <stdio.h>

void findPairWithSum(int arr[], int size, int targetSum)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == targetSum)
            {
                printf("Pair with sum %d found: (%d, %d)\n", targetSum, arr[i], arr[j]);
                return; // If a pair is found, exit the function
            }
        }
    }
    printf("Pair with sum %d not found\n", targetSum);
}

int main()
{
    int arr[] = {2, 7, 11, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 9;

    findPairWithSum(arr, size, targetSum);

    return 0;
}
