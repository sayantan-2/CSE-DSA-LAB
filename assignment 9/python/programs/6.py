def find_largest_consecutive_subarray(arr):
    max_length = 0
    max_start = 0
    num_set = set(arr)

    for num in arr:
        if num - 1 not in num_set:
            current_num = num
            current_length = 1

            while current_num + 1 in num_set:
                current_num += 1
                current_length += 1

            if current_length > max_length:
                max_length = current_length
                max_start = num

    largest_subarray = [i for i in range(max_start, max_start + max_length)]
    return largest_subarray


# Example usage
arr = [1, 3, 8, 4, 2, 2, 5, 6]
largest_subarray = find_largest_consecutive_subarray(arr)
print("Largest subarray formed by consecutive integers:", largest_subarray)
