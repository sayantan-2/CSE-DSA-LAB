lst = []
n = int(input("enter the number of elements in the list:"))
print(f"enter {n} new item for the list:")
for i in range(n):
    e = int(input())
    lst.append(e)
print("old list=", lst)
sp = int(input("enter the item after which the new item should be added:"))
if sp not in lst:
    print("item not in list")
else:
    new = int(input("enter the new element:"))
    pos = lst.index(sp)
    lst.insert(pos + 1, new)
    print("new list=", lst)
