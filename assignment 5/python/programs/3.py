class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyCircularLinkedList:
    def __init__(self):
        self.head = None

    # Insert a node at the beginning of the doubly circular linked list
    def insert_at_beginning(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            new_node.next = new_node
            new_node.prev = new_node
        else:
            last_node = self.head.prev
            new_node.next = self.head
            new_node.prev = last_node
            self.head.prev = new_node
            last_node.next = new_node
            self.head = new_node

    # Insert a node at the end of the doubly circular linked list
    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            new_node.next = new_node
            new_node.prev = new_node
        else:
            last_node = self.head.prev
            new_node.next = self.head
            new_node.prev = last_node
            self.head.prev = new_node
            last_node.next = new_node

    # Delete a node by value
    def delete(self, value):
        if self.head is None:
            return

        current = self.head

        while True:
            if current.data == value:
                if current.next == self.head:
                    self.head = None
                else:
                    current.prev.next = current.next
                    current.next.prev = current.prev
                    if self.head == current:
                        self.head = current.next
                return

            current = current.next
            if current == self.head:
                return

    # Display the doubly circular linked list in both forward and backward directions
    def display(self):
        if self.head is None:
            print("Doubly Circular Linked List is empty.")
            return

        print("Doubly Circular Linked List (Forward):", end=" ")
        current = self.head
        while True:
            print(current.data, end=" <-> ")
            current = current.next
            if current == self.head:
                break
        print("Head")

        print("Doubly Circular Linked List (Backward):", end=" ")
        current = self.head.prev
        while True:
            print(current.data, end=" <-> ")
            current = current.prev
            if current == self.head.prev:
                break
        print("Head")


if __name__ == "__main__":
    doubly_circular_linked_list = DoublyCircularLinkedList()

    # Insert elements into the doubly circular linked list
    doubly_circular_linked_list.insert_at_end(1)
    doubly_circular_linked_list.insert_at_end(2)
    doubly_circular_linked_list.insert_at_end(3)
    doubly_circular_linked_list.insert_at_beginning(0)
    doubly_circular_linked_list.insert_at_end(4)

    # Display the doubly circular linked list
    doubly_circular_linked_list.display()

    # Delete an element from the doubly circular linked list
    doubly_circular_linked_list.delete(2)

    # Display the doubly circular linked list after deletion
    doubly_circular_linked_list.display()
