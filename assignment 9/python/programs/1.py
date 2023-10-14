def find_pair_with_sum(arr, target_sum):
    # Create a dictionary to store elements and their indices
    num_indices = {}

    for index, num in enumerate(arr):
        # Calculate the complement of the current number
        complement = target_sum - num

        # If the complement is in the dictionary, we found a pair
        if complement in num_indices:
            return (complement, num)

        # Otherwise, add the current number and its index to the dictionary
        num_indices[num] = index

    # If no pair is found, return None
    return None


# Example usage
arr = [8, 7, 2, 5, 3, 1]
target_sum = 10
pair = find_pair_with_sum(arr, target_sum)

if pair is not None:
    print(f"Pair with the sum {target_sum}: {pair[0]} and {pair[1]}")
else:
    print("No pair found with the given sum.")
