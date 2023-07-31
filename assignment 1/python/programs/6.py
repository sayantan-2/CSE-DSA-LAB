arr = []
size = int(input("Enter the size of the array: "))
for i in range(size):
    element = int(input(f"Enter element {i+1}: "))
    arr.append(element)
n = int(input("Enter the index of the element to be deleted: "))
arr.pop(n)
print(arr)