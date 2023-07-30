og_lst=[[1,2,3],[4,5,6]]
print("old list:",og_lst)
lst=[]
n=int(input("enter the number of elements in the sub_list:"))
print(f"enter {n} new item for the sub_list:")
for i in range(n):
    e=int(input())
    lst.append(e)
og_lst.append(lst)
print("new list:",og_lst)