lst = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print("old",lst)
for i in range(len(lst)):
    lst[i] = lst[i] * lst[i]
print("new",lst)
