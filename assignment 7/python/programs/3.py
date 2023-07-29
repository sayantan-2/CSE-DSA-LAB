a=1
for i in range(0,4):
    for j in range(i,3):
        print(' ',end='')
    for k in range(0,i+1):
        print(a,end=' ')
        a=a+1
    print('')