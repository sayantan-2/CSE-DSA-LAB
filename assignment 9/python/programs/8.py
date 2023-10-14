def group_elements_by_first_occurrence(arr):
    element_indices = {}  # Dictionary to store the first occurrence indices of elements
    grouped_elements = {}

    for index, element in enumerate(arr):
        if element in element_indices:
            first_occurrence_index = element_indices[element]
            if element in grouped_elements:
                grouped_elements[element].append(
                    arr[first_occurrence_index : index + 1]
                )
            else:
                grouped_elements[element] = [arr[first_occurrence_index : index + 1]]
        else:
            element_indices[element] = index

    return list(grouped_elements.values())


# Example usage
arr = [1, 2, 3, 1, 2, 4, 5, 3, 6]
grouped = group_elements_by_first_occurrence(arr)
print("Grouped elements based on their first occurrence:")
for group in grouped:
    print(group)
