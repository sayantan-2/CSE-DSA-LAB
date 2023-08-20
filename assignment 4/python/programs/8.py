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


def swap_pairs(head):
    if head is None or head.next is None:
        return head

    new_head = head.next
    prev = None

    while head is not None and head.next is not None:
        next_node = head.next.next

        head.next.next = head
        if prev is not None:
            prev.next = head.next
        head.next = next_node

        prev = head
        head = next_node

    return new_head


if __name__ == "__main__":
    head = None

    num = int(input("Enter the number of elements in the list: "))
    print("Enter the elements:")
    for _ in range(num):
        data = int(input())
        head = insert(head, data)

    print("Original List:", end=" ")
    print_list(head)

    head = swap_pairs(head)

    print("List after Pairwise Swapping:", end=" ")
    print_list(head)
