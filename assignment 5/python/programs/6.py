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
            new_node.next = new_node
            new_node.prev = new_node
            self.head = new_node
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
            new_node.next = new_node
            new_node.prev = new_node
            self.head = new_node
        else:
            last_node = self.head.prev
            new_node.next = self.head
            new_node.prev = last_node
            self.head.prev = new_node
            last_node.next = new_node

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
                current.next.prev = new_node
                current.next = new_node
                new_node.prev = current
                return
            current = current.next
            if current == self.head:
                print(f"Element {key} not found in the list.")
                return
        print(f"Element {key} not found in the list.")

    # Delete a node by value
    def delete(self, data):
        if self.head is None:
            print("List is empty. Cannot perform deletion.")
            return
        current = self.head
        while True:
            if current.data == data:
                if current.next == self.head:
                    if current.prev == current:
                        self.head = None
                    else:
                        current.prev.next = self.head
                        self.head.prev = current.prev
                        self.head = current.next
                else:
                    current.prev.next = current.next
                    current.next.prev = current.prev
                return
            current = current.next
            if current == self.head:
                print(f"Element {data} not found in the list.")
                return

    # Display the doubly circular linked list
    def display(self):
        if self.head is None:
            print("Doubly Circular Linked List is empty.")
            return

        current = self.head
        while True:
            print(current.data, end=" <-> ")
            current = current.next
            if current == self.head:
                break
        print("Head")


if __name__ == "__main__":
    doubly_circular_linked_list = DoublyCircularLinkedList()

    # Insert elements into the doubly circular linked list
    doubly_circular_linked_list.insert_at_end(1)
    doubly_circular_linked_list.insert_at_end(2)
    doubly_circular_linked_list.insert_at_end(3)

    # Display the doubly circular linked list
    print("Doubly Circular Linked List:")
    doubly_circular_linked_list.display()

    # Insert an element after a specific element
    doubly_circular_linked_list.insert_after(4, 2)

    # Display the doubly circular linked list after insertion
    print("Doubly Circular Linked List after Insertion:")
    doubly_circular_linked_list.display()

    # Delete an element from the doubly circular linked list
    doubly_circular_linked_list.delete(2)

    # Display the doubly circular linked list after deletion
    print("Doubly Circular Linked List after Deletion:")
    doubly_circular_linked_list.display()
