def highest_ratio():
    N = int(input("Enter the number of students: "))
    print("Height in m and weight in kg")
    data = []
    for i in range(N):
        height = float(input(f"Enter the height of student {i+1}: "))
        weight = float(input(f"Enter the weight of student {i+1}: "))
        data.append((height, weight))
    max_ratio = 0
    for i in range(N):
        height, weight = data[i]
        ratio = weight / height
        if ratio > max_ratio:
            max_ratio = ratio
    return max_ratio


print(highest_ratio())
