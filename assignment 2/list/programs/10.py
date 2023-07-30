lst=[1,1,2,3,2,8,4,73,2,6,9]
print("old:",lst)
n=int(input("enter the item to be removed:"))
if n in lst:
    while n in lst:
        lst.remove(n)
    print("new:",lst)
else:
    print("item not found")