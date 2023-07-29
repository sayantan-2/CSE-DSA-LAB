//wap to remove duplicate elements from an array
#include <stdio.h>

void deleteDuplicates(int array[], int *size) {
    for (int i = 0; i < *size; i++) {
        for (int j = i + 1; j < *size; j++) {
            if (array[i] == array[j]) {
                // Shift elements to the left to remove the duplicate
                for (int k = j; k < (*size) - 1; k++) {
                    array[k] = array[k + 1];
                }
                (*size)--;
                j--; // Re-check the current index, as it has a new element after the shift
            }
        }
    }
}

int main() {
    int array[] = {2, 4, 6, 4, 8, 2, 10, 6};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    deleteDuplicates(array, &size);

    printf("Array with duplicates removed: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
