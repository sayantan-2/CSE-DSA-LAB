def find_subarrays_with_zero_sum(arr):
    # Create a dictionary to store the prefix sum and its indices
    prefix_sum_indices = {}
    prefix_sum = 0

    for i, num in enumerate(arr):
        prefix_sum += num

        # If the current prefix sum is 0 or it's already in the dictionary,
        # it means there is a subarray with a zero sum
        if prefix_sum == 0:
            print(f"Subarray from index 0 to {i}: {arr[0:i+1]}")

        if prefix_sum in prefix_sum_indices:
            # Print all subarrays between the current index and the stored index
            for start_index in prefix_sum_indices[prefix_sum]:
                print(
                    f"Subarray from index {start_index+1} to {i}: {arr[start_index+1:i+1]}"
                )

        # Add the current prefix sum and its index to the dictionary
        if prefix_sum not in prefix_sum_indices:
            prefix_sum_indices[prefix_sum] = []
        prefix_sum_indices[prefix_sum].append(i)


# Example usage
arr = [4, 2, -3, 1, 6, -6, -2]
find_subarrays_with_zero_sum(arr)
