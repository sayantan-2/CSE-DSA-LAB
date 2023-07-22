n=int(input("enter limit-"))
a=0
b=1
c=a+b
s=1+c*c

while(s<=n):
    a=b
    b=c
    c=a+b
    s=s+c*c
print(s)