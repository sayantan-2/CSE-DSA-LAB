def find_max_length_subarray_equal_01(arr):
    max_length = 0
    prefix_sum = 0
    sum_indices = {0: -1}

    for i, num in enumerate(arr):
        if num == 0:
            prefix_sum -= 1
        else:
            prefix_sum += 1

        if prefix_sum in sum_indices:
            subarray_length = i - sum_indices[prefix_sum]
            if subarray_length > max_length:
                max_length = subarray_length
        else:
            sum_indices[prefix_sum] = i

    return max_length


# Example usage
arr = [0, 1, 0, 1, 1, 1, 0, 0]
max_length = find_max_length_subarray_equal_01(arr)
print("Maximum length subarray with an equal number of 0's and 1's:", max_length)
