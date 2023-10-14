def find_odd_occurrence(arr):
    count_dict = {}  # Create a dictionary to store counts

    # Count the occurrences of each number in the list
    for num in arr:
        if num in count_dict:
            count_dict[num] += 1
        else:
            count_dict[num] = 1

    # Find the number with an odd occurrence
    for num, count in count_dict.items():
        if count % 2 != 0:
            return num

    return None  # If no number with an odd occurrence is found


# Example usage:
my_list = [3, 6, 8, 12, 15, 24, 15, 35, 35, 48, 6]

odd_occurrence_number = find_odd_occurrence(my_list)

if odd_occurrence_number is not None:
    print(f"The number occurring an odd number of times is: {odd_occurrence_number}")
else:
    print("No number occurring an odd number of times.")
