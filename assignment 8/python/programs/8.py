#python program to find 2nd highest number in an array
def find_second_highest(arr):
    if len(arr) < 2:
        return "Array should have at least 2 elements"
    highest = max(arr[0], arr[1])
    second_highest = min(arr[0], arr[1])
    for i in range(2, len(arr)):
        if arr[i] > highest:
            second_highest = highest
            highest = arr[i]
        elif arr[i] > second_highest and arr[i] != highest:
            second_highest = arr[i]
    return second_highest
 
arr=[5, 2, 9, 1, 8, 3, 7, 6, 10, 4, 2, 6, 3, 1, 9, 7, 8, 4, 10, 2s5]
second_highest = find_second_highest(arr)
print(second_highest)