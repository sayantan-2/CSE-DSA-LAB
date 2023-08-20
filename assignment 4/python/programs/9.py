class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def create_node(data):
    return Node(data)


def insert(head, data):
    new_node = create_node(data)

    if head is None:
        head = new_node
    else:
        temp = head
        while temp.next is not None:
            temp = temp.next
        temp.next = new_node

    return head


def print_list(head):
    while head is not None:
        print(head.data, end=" ")
        head = head.next
    print()


def has_loop(head):
    slow = head
    fast = head

    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            return True  # Loop detected

    return False  # No loop


if __name__ == "__main__":
    head = None

    num = int(input("Enter the number of elements in the list: "))
    print("Enter the elements:")
    for _ in range(num):
        data = int(input())
        head = insert(head, data)

    # Creating a loop for demonstration purposes
    if num >= 3:
        temp = head
        for _ in range(num - 1):
            temp = temp.next
        temp.next = head

    if has_loop(head):
        print("The linked list contains a loop.")
    else:
        print("The linked list does not contain a loop.")
