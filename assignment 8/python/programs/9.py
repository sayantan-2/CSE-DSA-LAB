def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        left = [x for x in arr[1:] if x <= pivot]
        right = [x for x in arr[1:] if x > pivot]
        return quick_sort(left) + [pivot] + quick_sort(right)


# Example usage:
my_list = [64, 34, 25, 12, 22, 11, 90]

sorted_list = quick_sort(my_list)

print("Sorted array using Quick Sort:")
print(sorted_list)
