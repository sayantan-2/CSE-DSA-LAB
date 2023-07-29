for i in range(0,4):
    for j in range(i,3):
        print(' ',end='')
    for k in range(0,i+1):
        print(chr(65+i),end=' ')
    print('')