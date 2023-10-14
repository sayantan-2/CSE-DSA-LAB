def interpolation_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right and arr[left] <= target <= arr[right]:
        # Calculate the estimated position using interpolation formula
        pos = left + ((target - arr[left]) * (right - left) // (arr[right] - arr[left]))

        if arr[pos] == target:
            return pos  # Target found, return the index
        elif arr[pos] < target:
            left = pos + 1  # Target is in the right half of the remaining array
        else:
            right = pos - 1  # Target is in the left half of the remaining array

    return -1  # Target not found in the list


# Example usage:
my_list = [3, 6, 8, 12, 15, 24, 35, 48]
target_element = 15

# Interpolation search requires the list to be sorted
my_list.sort()

result = interpolation_search(my_list, target_element)

if result != -1:
    print(f"Element {target_element} found at index {result}")
else:
    print(f"Element {target_element} not found in the list.")
