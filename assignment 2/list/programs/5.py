list2=[8,9,10,11,12,13,14]
list1=[1,2,3,4,5,6,7]
for i,j in zip(list1,list2[::-1]):
    print(i,j)
