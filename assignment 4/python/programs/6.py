class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def insert(head, data):
    new_node = Node(data)
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


def left_shift_linked_list(head, k):
    if head is None or k == 0:
        return head

    current = head
    length = 0

    # Count the number of nodes in the linked list
    while current is not None:
        length += 1
        current = current.next

    # Normalize the value of k
    k = k % length

    if k == 0:
        return head

    current = head

    # Find the (N - k)th node
    for i in range(1, length - k):
        current = current.next

    new_head = current.next
    current.next = None

    # Traverse to the end of the newHead list
    temp = new_head
    while temp.next is not None:
        temp = temp.next

    # Update the end of the newHead list to point to the original head
    temp.next = head

    return new_head


if __name__ == "__main__":
    head = None

    num = int(input("Enter the number of elements in the linked list: "))

    print("Enter the elements:")
    for i in range(num):
        data = int(input())
        head = insert(head, data)

    k = int(input("Enter the value of k: "))

    print("Original Linked List: ")
    print_list(head)

    shifted_head = left_shift_linked_list(head, k)

    print("Left-Shifted Linked List: ")
    print_list(shifted_head)
