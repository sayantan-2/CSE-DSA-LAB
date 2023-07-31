# a python program to delete duplicate elements from array
arr = []
size = int(input("Enter the size of the array: "))
for i in range(size):
    element = int(input(f"Enter element {i+1}: "))
    arr.append(element)
arr2 = []

for i in range(size):
    if arr[i] not in arr[i + 1 : size]:
        arr2.append(arr[i])

print(arr2)
