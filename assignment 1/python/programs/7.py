#a python program to delete duplicate elements from array

arr=[1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10]
arr2=[]

for i in range(len(arr)):
        if arr[i] not in arr[i+1:len(arr)]:
            arr2.append(arr[i])

print(arr2)