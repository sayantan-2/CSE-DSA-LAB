class Node:
    def __init__(self, item):
        self.item = item
        self.next = None


START = None


def create_list(item):
    global START
    temp = Node(item)
    temp.next = None
    if START is None:
        START = temp
    else:
        ptr = START
        while ptr.next is not None:
            ptr = ptr.next
        ptr.next = temp


def insert_at_specific(data, loc):
    global START
    temp = Node(data)
    temp.next = None
    p = START
    for i in range(1, loc - 1):
        p = p.next
    temp.next = p.next
    p.next = temp


def delete_at_end():
    global START
    p = START
    q = None
    if p.next is None:
        START = None
    else:
        while p.next is not None:
            q = p
            p = p.next
        q.next = None


n = int(input("Enter the number of items: "))

for _ in range(n):
    data = int(input("Enter the data item: "))
    create_list(data)

loc = int(input("Enter the location where you want to insert an item: "))
item_to_insert = int(input("Enter the item you want to insert: "))
insert_at_specific(item_to_insert, loc)

item_to_delete_at_end = int(
    input(
        "Do you want to delete an item at the end of the list? Enter 1 for yes and 0 for no: "
    )
)
if item_to_delete_at_end == 1:
    delete_at_end()

p = START
print("START", end="")
while p is not None:
    print(f"--> {p.item}", end="")
    p = p.next
print()
