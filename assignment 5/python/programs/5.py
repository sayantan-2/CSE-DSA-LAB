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

    # Insert a node after a specific element
    def insert_after(self, data, key):
        new_node = Node(data)
        if self.head is None:
            print("List is empty. Cannot perform insertion.")
            return
        current = self.head
        while current:
            if current.data == key:
                new_node.next = current.next
                if current.next is not None:
                    current.next.prev = new_node
                current.next = new_node
                new_node.prev = current
                return
            current = current.next
        print(f"Element {key} not found in the list.")

    # Delete a node by value
    def delete(self, data):
        if self.head is None:
            print("List is empty. Cannot perform deletion.")
            return
        current = self.head

        while current:
            if current.data == data:
                if current.prev is not None:
                    current.prev.next = current.next
                else:
                    self.head = current.next

                if current.next is not None:
                    current.next.prev = current.prev
                return
            current = current.next

        print(f"Element {data} not found in the list.")

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
    doubly_linked_list.insert_at_end(1)
    doubly_linked_list.insert_at_end(2)
    doubly_linked_list.insert_at_end(3)

    # Display the doubly linked list
    print("Doubly Linked List:")
    doubly_linked_list.display()

    # Insert an element after a specific element
    doubly_linked_list.insert_after(4, 2)

    # Display the doubly linked list after insertion
    print("Doubly Linked List after Insertion:")
    doubly_linked_list.display()

    # Delete an element from the doubly linked list
    doubly_linked_list.delete(2)

    # Display the doubly linked list after deletion
    print("Doubly Linked List after Deletion:")
    doubly_linked_list.display()
