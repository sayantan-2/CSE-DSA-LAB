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

    # Remove a particular character from the doubly linked list
    def remove_character(self, char_to_remove):
        if self.head is None:
            print("List is empty. Cannot remove character.")
            return

        current = self.head
        while current:
            if current.data == char_to_remove:
                if current.prev:
                    current.prev.next = current.next
                else:
                    self.head = current.next

                if current.next:
                    current.next.prev = current.prev
                return
            current = current.next

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
    doubly_linked_list.insert_at_end("A")
    doubly_linked_list.insert_at_end("B")
    doubly_linked_list.insert_at_end("C")
    doubly_linked_list.insert_at_end("D")

    # Display the doubly linked list
    print("Doubly Linked List:")
    doubly_linked_list.display()

    # Remove a particular character from the doubly linked list
    char_to_remove = "B"
    doubly_linked_list.remove_character(char_to_remove)

    # Display the doubly linked list after removal
    print(f"Doubly Linked List after removing '{char_to_remove}':")
    doubly_linked_list.display()
