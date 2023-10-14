def has_subarray_with_zero_sum(arr):
    # Create a set to store the prefix sum
    prefix_sum_set = set()
    prefix_sum = 0

    for num in arr:
        prefix_sum += num

        # If the current prefix sum is already in the set, a subarray with a sum of 0 exists
        if prefix_sum in prefix_sum_set or prefix_sum == 0:
            return True

        # Add the current prefix sum to the set
        prefix_sum_set.add(prefix_sum)

    # If no subarray with a sum of 0 is found, return False
    return False


# Example usage
arr = [4, 2, -3, 1, 6]
if has_subarray_with_zero_sum(arr):
    print("Subarray with a sum of 0 exists")
else:
    print("No subarray with a sum of 0")
