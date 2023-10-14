def find_min_repeating_index(arr):
    element_indices = {}  # Dictionary to store the indices of elements
    min_repeating_index = float("inf")

    for index, element in enumerate(arr):
        if element in element_indices:
            min_repeating_index = min(min_repeating_index, element_indices[element])
        else:
            element_indices[element] = index

    if min_repeating_index == float("inf"):
        return -1  # No repeating element found
    else:
        return min_repeating_index


# Example usage
arr = [4, 2, 6, 1, 6, 5, 8, 2]
min_index = find_min_repeating_index(arr)
if min_index == -1:
    print("No repeating element found.")
else:
    print("Minimum index of a repeating element:", min_index)
