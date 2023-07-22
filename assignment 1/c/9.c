//program to find frequency of a given number k
#include <stdio.h>

int findFrequency(int array[], int size, int k) {
    int frequency = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] == k) {
            frequency++;
        }
    }

    return frequency;
}

int main() {
    int array[] = {2, 5, 7, 5, 9, 2, 1, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int k;

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Enter the number to find its frequency: ");
    scanf("%d", &k);

    int frequency = findFrequency(array, size, k);
    printf("Frequency of %d in the array: %d\n", k, frequency);

    return 0;
}
