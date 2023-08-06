matrix = [[0, 0, 3, 0, 4], [0, 0, 5, 7, 0], [0, 0, 0, 0, 0], [0, 2, 6, 0, 0]]
c = 0
e = 0
for i in range(len(matrix)):
    c = c + matrix[i].count(0)
    e = e + len(matrix[i])
print("The matrix is sparse matrix" if c > e // 2 else "not a sparse matrix")