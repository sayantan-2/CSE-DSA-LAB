#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int frequency;
    int index;
} Element;

int compareElements(const void *a, const void *b)
{
    Element *elementA = (Element *)a;
    Element *elementB = (Element *)b;

    // Sort by frequency in ascending order
    if (elementA->frequency < elementB->frequency)
        return -1;
    if (elementA->frequency > elementB->frequency)
        return 1;

    // If frequencies are equal, sort by index in ascending order
    if (elementA->index < elementB->index)
        return -1;
    if (elementA->index > elementB->index)
        return 1;

    return 0;
}

void sortByFrequencyAndIndex(int arr[], int size)
{
    Element *elements = (Element *)malloc(size * sizeof(Element));

    // Initialize the Element array with values, frequencies, and indices
    for (int i = 0; i < size; i++)
    {
        elements[i].value = arr[i];
        elements[i].frequency = 0;
        elements[i].index = i;
    }

    // Count the frequency of each element
    for (int i = 0; i < size; i++)
    {
        int value = elements[i].value;
        elements[i].frequency = 1;

        for (int j = i + 1; j < size; j++)
        {
            if (elements[j].value == value)
            {
                elements[i].frequency++;
                elements[j].value = -1; // Mark as seen
            }
        }
    }

    // Sort the elements using the custom comparison function
    qsort(elements, size, sizeof(Element), compareElements);

    // Print the sorted elements
    printf("Sorted by frequency and index:\n");
    for (int i = 0; i < size; i++)
    {
        if (elements[i].value != -1)
        {
            printf("%d ", elements[i].value);
        }
    }

    free(elements);
}

int main()
{
    int arr[] = {2, 3, 2, 4, 2, 6, 5, 4, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    sortByFrequencyAndIndex(arr, size);

    return 0;
}
