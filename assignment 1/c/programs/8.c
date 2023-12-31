#include <stdio.h>

int findSecondHighest(int array[], int size) {
    if (size < 2) {
        printf("The array should have at least two elements.\n");
        return -1;
    }

    int highest = array[0];
    int secondHighest = array[1];

    if (secondHighest > highest) {
        // Swap highest and secondHighest if needed
        int temp = highest;
        highest = secondHighest;
        secondHighest = temp;
    }

    for (int i = 2; i < size; i++) {
        if (array[i] > highest) {
            // Update highest and shift the previous highest to second highest
            secondHighest = highest;
            highest = array[i];
        } else if (array[i] > secondHighest && array[i] != highest) {
            // Update secondHighest if a new second highest element is found
            secondHighest = array[i];
        }
    }

    return secondHighest;
}

int main() {
    int array[100];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int secondHighest = findSecondHighest(array, size);

    if (secondHighest != -1) {
        printf("The second highest element is: %d\n", secondHighest);
    }

    return 0;
}