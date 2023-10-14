def find_pairs_with_difference(arr, k):
    pair_set = set()
    result = []

    for num in arr:
        if num - k in pair_set:
            result.append((num - k, num))
        if num + k in pair_set:
            result.append((num, num + k))

        pair_set.add(num)

    return result


# Example usage
arr = [1, 5, 3, 4, 2]
k = 2
pairs = find_pairs_with_difference(arr, k)

for pair in pairs:
    print(f"Pair with a difference of {k}: {pair[0]} and {pair[1]}")
