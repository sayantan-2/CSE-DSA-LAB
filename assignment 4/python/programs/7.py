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


def reverse_list(head):
    prev = None
    current = head

    while current is not None:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node

    return prev


if __name__ == "__main__":
    head = None

    num = int(input("Enter the number of elements in the list: "))
    print("Enter the elements:")
    for _ in range(num):
        data = int(input())
        head = insert(head, data)

    print("Original List:", end=" ")
    print_list(head)

    head = reverse_list(head)

    print("Reversed List:", end=" ")
    print_list(head)
