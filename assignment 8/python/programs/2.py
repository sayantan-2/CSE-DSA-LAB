def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2  # Calculate the middle index

        if arr[mid] == target:
            return mid  # Target found, return the index
        elif arr[mid] < target:
            left = mid + 1  # Target is in the right half of the remaining array
        else:
            right = mid - 1  # Target is in the left half of the remaining array

    return -1  # Target not found in the list


# Example usage:
my_list = [3, 6, 8, 12, 15, 24, 35, 48]
target_element = 15

# Binary search requires the list to be sorted
my_list.sort()

result = binary_search(my_list, target_element)

if result != -1:
    print(f"Element {target_element} found at index {result}")
else:
    print(f"Element {target_element} not found in the list.")
