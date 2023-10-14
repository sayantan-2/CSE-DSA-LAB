def find_triplets_with_sum(arr, K):
    arr.sort()
    triplets = []
    n = len(arr)

    for i in range(n - 2):
        left = i + 1
        right = n - 1

        while left < right:
            current_sum = arr[i] + arr[left] + arr[right]

            if current_sum == K:
                triplets.append((arr[i], arr[left], arr[right]))
                left += 1
                right -= 1
            elif current_sum < K:
                left += 1
            else:
                right -= 1

    return triplets


# Example usage:
my_array = [1, 4, 45, 6, 10, 8, 12, 16]
target_sum = 22

result = find_triplets_with_sum(my_array, target_sum)

if result:
    print(f"Triplets with sum {target_sum} are:")
    for triplet in result:
        print(triplet)
else:
    print("No triplets found with the given sum.")
