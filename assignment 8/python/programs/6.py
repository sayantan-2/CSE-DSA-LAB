def selection_sort(arr):
    n = len(arr)

    for i in range(n):
        min_index = i

        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        # Swap the minimum element with the first element of the unsorted part
        arr[i], arr[min_index] = arr[min_index], arr[i]


# Example usage:
my_list = [64, 34, 25, 12, 22, 11, 90]

selection_sort(my_list)

print("Sorted array using Selection Sort:")
print(my_list)
