from collections import defaultdict


def sort_by_frequency_and_index(arr):
    element_indices = defaultdict(list)
    frequency_count = defaultdict(int)

    # Populate element_indices and frequency_count dictionaries
    for i, element in enumerate(arr):
        element_indices[element].append(i)
        frequency_count[element] += 1

    # Sort the array using custom sorting criteria
    sorted_arr = sorted(arr, key=lambda x: (-frequency_count[x], element_indices[x][0]))

    return sorted_arr


# Example usage
arr = [4, 2, 4, 6, 2, 8, 2, 5]
sorted_array = sort_by_frequency_and_index(arr)
print("Sorted elements by frequency and index:", sorted_array)
