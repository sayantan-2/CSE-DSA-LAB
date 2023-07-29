// Write a program to merge two sorted array of length M & N

#include <stdio.h>

void mergeArrays(int array1[], int M, int array2[], int N, int mergedArray[]) {
    int i = 0, j = 0, k = 0;

    while (i < M && j < N) {
        if (array1[i] <= array2[j]) {
            mergedArray[k++] = array1[i++];
        } else {
            mergedArray[k++] = array2[j++];
        }
    }

    // Copy the remaining elements from array1, if any
    while (i < M) {
        mergedArray[k++] = array1[i++];
    }

    // Copy the remaining elements from array2, if any
    while (j < N) {
        mergedArray[k++] = array2[j++];
    }
}

int main() {
    int array1[] = {1, 3, 5, 7, 9};
    int M = sizeof(array1) / sizeof(array1[0]);

    int array2[] = {2, 4, 6, 8, 10, 12};
    int N = sizeof(array2) / sizeof(array2[0]);

    int mergedArray[M + N];

    printf("Array 1: ");
    for (int i = 0; i < M; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");

    printf("Array 2: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");

    mergeArrays(array1, M, array2, N, mergedArray);

    printf("Merged and sorted array: ");
    for (int i = 0; i < M + N; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}
