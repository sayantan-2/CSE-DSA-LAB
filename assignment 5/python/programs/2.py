class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None

    # Insert a node at the beginning of the doubly linked list
    def insert_at_beginning(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

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

    # Delete a node by value
    def delete(self, value):
        if self.head is None:
            return

        current = self.head

        # Check if the node to delete is the head
        if current.data == value:
            self.head = current.next
            if self.head is not None:
                self.head.prev = None
            return

        while current is not None:
            if current.data == value:
                if current.next is not None:
                    current.prev.next = current.next
                    current.next.prev = current.prev
                else:
                    current.prev.next = None
                return
            current = current.next

    # Display the doubly linked list in both forward and backward directions
    def display(self):
        if self.head is None:
            print("Doubly Linked List is empty.")
            return

        print("Doubly Linked List (Forward):", end=" ")
        current = self.head
        while current is not None:
            print(current.data, end=" <-> ")
            current = current.next
        print("None")

        print("Doubly Linked List (Backward):", end=" ")
        current = self.head
        while current.next is not None:
            current = current.next
        while current is not None:
            print(current.data, end=" <-> ")
            current = current.prev
        print("None")


if __name__ == "__main__":
    doubly_linked_list = DoublyLinkedList()

    # Insert elements into the doubly linked list
    doubly_linked_list.insert_at_end(1)
    doubly_linked_list.insert_at_end(2)
    doubly_linked_list.insert_at_end(3)
    doubly_linked_list.insert_at_beginning(0)
    doubly_linked_list.insert_at_end(4)

    # Display the doubly linked list
    doubly_linked_list.display()

    # Delete an element from the doubly linked list
    doubly_linked_list.delete(2)

    # Display the doubly linked list after deletion
    doubly_linked_list.display()
