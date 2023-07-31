arr = []
size = int(input("Enter the size of the array: "))

for i in range(size):
    element = int(input(f"Enter element {i+1}: "))
    arr.append(element)

k = int(input("Enter the location: "))
n = int(input("Enter the number: "))

arr.insert(k, n)
print(arr)