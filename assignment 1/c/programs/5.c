#include <stdio.h>

int main()
{
    int arr[11];
    int k, n;

    printf("Enter 10 elements in the array:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the location: ");
    scanf("%d", &k);
    printf("Enter the number: ");
    scanf("%d", &n);

    if (k < 0 || k > 10)
    {
        printf("Invalid location!\n");
        return 0;
    }

    for (int i = 10; i >= k; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[k] = n;

    printf("Updated array: ");
    for (int i = 0; i <= 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}