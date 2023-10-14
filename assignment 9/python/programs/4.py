def find_max_length_subarray_with_sum(arr, target_sum):
    max_length = 0
    prefix_sum = 0
    sum_indices = {0: -1}

    for i, num in enumerate(arr):
        prefix_sum += num

        if prefix_sum - target_sum in sum_indices:
            subarray_length = i - sum_indices[prefix_sum - target_sum]
            if subarray_length > max_length:
                max_length = subarray_length

        if prefix_sum not in sum_indices:
            sum_indices[prefix_sum] = i

    return max_length


# Example usage
arr = [1, -1, 5, -2, 3]
target_sum = 3
max_length = find_max_length_subarray_with_sum(arr, target_sum)
print("Maximum length of subarray with sum", target_sum, "is", max_length)
