lst=[1,2,3,4,5,6,7,8,9]
print("old list:",lst)
n=int(input("enter the num to be replaced:"))
if n in lst:
    new=int(input("enter the new number:"))
    pos=lst.index(n)
    lst[pos]=new
    print("new list:",lst)
else:
    print("no such element in the list")