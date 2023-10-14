#include <stdio.h>

// Function to perform interpolation search
int interpolationSearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right && target >= arr[left] && target <= arr[right])
    {
        // Calculate the position using linear interpolation
        int pos = left + ((double)(target - arr[left]) / (arr[right] - arr[left])) * (right - left);

        if (arr[pos] == target)
        {
            return pos; // Return the index where the target is found
        }

        if (arr[pos] < target)
        {
            left = pos + 1;
        }
        else
        {
            right = pos - 1;
        }
    }

    return -1; // Return -1 if the target is not found
}

int main()
{
    int arr[] = {2, 5, 7, 10, 12, 15, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int result = interpolationSearch(arr, size, target);

    if (result != -1)
    {
        printf("Element %d found at index %d.\n", target, result);
    }
    else
    {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
