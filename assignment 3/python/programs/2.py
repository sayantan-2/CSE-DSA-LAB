def spiral_matrix(n):
    matrix = [[0 for x in range(n)] for y in range(n)]
    count = 1
    for layer in range((n + 1) // 2):
        for i in range(layer, n - layer):
            matrix[layer][i] = count
            count += 1
        for i in range(layer + 1, n - layer):
            matrix[i][n - layer - 1] = count
            count += 1
        for i in range(layer + 1, n - layer):
            matrix[n - layer - 1][n - i - 1] = count
            count += 1
        for i in range(layer + 1, n - layer - 1):
            matrix[n - i - 1][layer] = count
            count += 1
    return matrix


n = 3
result = spiral_matrix(n)
for row in result:
    print(row)
