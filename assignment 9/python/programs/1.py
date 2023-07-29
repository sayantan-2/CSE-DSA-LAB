a=1
for i in range(0,5):
    for j in range(0,i+1):
        if a%2!=0:
            print("*",end='')
        else:
            print("#",end='')
        a=a+1
    print()