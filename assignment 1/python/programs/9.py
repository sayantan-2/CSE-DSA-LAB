# Write a program to find frequency of a given number ‘k’
arr = []
size = int(input("Enter the size of the array: "))
for i in range(size):
    element = int(input(f"Enter element {i+1}: "))
    arr.append(element)
k=int(input("enter the number:"))
count=arr.count(k)
print(count)