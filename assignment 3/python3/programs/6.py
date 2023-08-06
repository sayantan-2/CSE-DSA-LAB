def printmatrix(matrix):
    row = len(matrix)
    col = len(matrix[0])
    for i in range(row):
        for j in range(col):
            print(matrix[i][j], end="\t")
        print()


matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

print("original matrix:")
printmatrix(matrix)

print("enter the rows you want to interchange")
r1 = int(input())
r2 = int(input())

matrix[r1 - 1], matrix[r2 - 1] = matrix[r2 - 1], matrix[r1 - 1]

print("after:")
printmatrix(matrix)