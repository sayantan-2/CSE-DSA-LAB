def printmatrix(matrix):
    row=len(matrix)
    col=len(matrix[0])
    for i in range(row):
        for j in range(col):
            print(matrix[i][j], end="\t")
        print()
mat=[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
print("old matrix:")
printmatrix(mat)
n=0
mat_new = [[0 for x in range(4)] for y in range(4)]
for i in range(4,0,-1):
    for j in range(4):
        mat_new[j][i-1]=mat[n][j]
    n=n+1
print("new matrix:")
printmatrix(mat_new)