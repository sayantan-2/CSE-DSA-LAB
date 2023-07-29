#a program to delete a element fron an array
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
n = int(input("Enter the index of the element to be deleted: "))
arr.pop(n)
print(arr)