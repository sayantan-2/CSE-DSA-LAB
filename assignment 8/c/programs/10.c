#include <stdio.h>

void findTriplets(int arr[], int size, int K)
{
    int found = 0;

    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (arr[i] + arr[j] + arr[k] == K)
                {
                    printf("Triplets: %d, %d, %d\n", arr[i], arr[j], arr[k]);
                    found = 1;
                }
            }
        }
    }

    if (!found)
    {
        printf("No triplets found with the sum %d.\n", K);
    }
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int K = 22;

    findTriplets(arr, size, K);

    return 0;
}
