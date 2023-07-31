m = []
size = int(input("Enter the size of the 1st array: "))
for i in range(size):
    element = int(input(f"Enter element {i+1}: "))
    m.append(element)
n = []
size = int(input("Enter the size of the 2nd array: "))
for i in range(size):
    element = int(input(f"Enter element {i+1}: "))
    n.append(element)
m.extend(n)
print(m)