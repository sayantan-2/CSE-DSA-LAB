class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyCircularLinkedList:
    def __init__(self):
        self.head = None

    # Insert a node at the beginning of the circular linked list
    def insert_at_beginning(self, data):
        new_node = Node(data)
        if self.head is None:
            new_node.next = new_node
            self.head = new_node
        else:
            current = self.head
            while current.next != self.head:
                current = current.next
            new_node.next = self.head
            current.next = new_node
            self.head = new_node

    # Insert a node at the end of the circular linked list
    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            new_node.next = new_node
            self.head = new_node
        else:
            current = self.head
            while current.next != self.head:
                current = current.next
            new_node.next = self.head
            current.next = new_node

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
                current.next = new_node
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
        prev = None
        while True:
            if current.data == data:
                if current.next == self.head:
                    if prev:
                        prev.next = self.head
                    else:
                        self.head = None
                else:
                    if prev:
                        prev.next = current.next
                    else:
                        temp = self.head
                        while temp.next != self.head:
                            temp = temp.next
                        self.head = current.next
                        temp.next = self.head
                return
            prev = current
            current = current.next
            if current == self.head:
                print(f"Element {data} not found in the list.")
                return

    # Display the circular linked list
    def display(self):
        if self.head is None:
            print("Circular Linked List is empty.")
            return

        current = self.head
        while True:
            print(current.data, end=" -> ")
            current = current.next
            if current == self.head:
                break
        print("Head")


if __name__ == "__main__":
    circular_linked_list = SinglyCircularLinkedList()

    # Insert elements into the circular linked list
    circular_linked_list.insert_at_end(1)
    circular_linked_list.insert_at_end(2)
    circular_linked_list.insert_at_end(3)

    # Display the circular linked list
    print("Circular Linked List:")
    circular_linked_list.display()

    # Insert an element after a specific element
    circular_linked_list.insert_after(4, 2)

    # Display the circular linked list after insertion
    print("Circular Linked List after Insertion:")
    circular_linked_list.display()

    # Delete an element from the circular linked list
    circular_linked_list.delete(2)

    # Display the circular linked list after deletion
    print("Circular Linked List after Deletion:")
    circular_linked_list.display()
