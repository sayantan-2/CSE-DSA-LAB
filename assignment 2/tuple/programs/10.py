# check if all the items in the tuple are same
tpl=(1,1,1,1,1,1)
c=tpl.count(tpl[0])
if c == len(tpl):
    print("all the items are same in the tuple:",tpl)
else:
    print("all the items are not same in the tuple:",tpl)
    