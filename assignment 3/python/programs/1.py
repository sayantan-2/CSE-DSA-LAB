m = int(input("Enter the number of rows: "))
n = int(input("Enter the number of columns: "))

matrix = []

for i in range(m):
    row = []
    for j in range(n):
        element = int(input(f"Enter element [{i}][{j}]: "))
        row.append(element)
    matrix.append(row)

for i in range(m):
    for j in range(n):
        print(matrix[i][j], end=" ")
    print()

s = 0
for i in range(m):
    s = s + matrix[i][i]
print("sum of principle diagonal:", s)
s = 0
for i in range(m):
    for j in range(n):
        if i + j == m - 1:
            s = s + matrix[i][j]
print("sum of anti diagonal:", s)
