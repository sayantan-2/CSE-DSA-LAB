class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None

    # Insert a node at the end of the doubly linked list
    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = new_node
            new_node.prev = current

    # Reverse the doubly linked list
    def reverse(self):
        if self.head is None or self.head.next is None:
            return

        prev_node = None
        current = self.head

        while current is not None:
            next_node = current.next
            current.next = prev_node
            current.prev = next_node
            prev_node = current
            current = next_node

        self.head = prev_node

    # Display the doubly linked list
    def display(self):
        if self.head is None:
            print("Doubly Linked List is empty.")
            return

        current = self.head
        while current is not None:
            print(current.data, end=" <-> ")
            current = current.next
        print("None")


if __name__ == "__main__":
    doubly_linked_list = DoublyLinkedList()

    # Insert elements into the doubly linked list
    for data in [1, 2, 3, 4, 5]:
        doubly_linked_list.insert_at_end(data)

    # Display the original doubly linked list
    print("Original Doubly Linked List:")
    doubly_linked_list.display()

    # Reverse the doubly linked list
    doubly_linked_list.reverse()

    # Display the reversed doubly linked list
    print("Reversed Doubly Linked List:")
    doubly_linked_list.display()
