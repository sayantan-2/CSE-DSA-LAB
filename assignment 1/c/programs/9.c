#include <stdio.h>

int findFrequency(int array[], int size, int k)
{
    int frequency = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] == k)
        {
            frequency++;
        }
    }

    return frequency;
}

int main()
{
    int array[100];
    int size;
    int k;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Enter the number to find its frequency: ");
    scanf("%d", &k);

    int frequency = findFrequency(array, size, k);
    printf("Frequency of %d in the array: %d\n", k, frequency);

    return 0;
}