class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyCircularLinkedList:
    def __init__(self):
        self.head = None

    # Insert a node at the end of the circular linked list
    def insert(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.head.next = self.head
        else:
            current = self.head
            while current.next != self.head:
                current = current.next
            current.next = new_node
            new_node.next = self.head

    # Display the circular linked list
    def display(self):
        if not self.head:
            print("Circular Linked List is empty.")
            return

        current = self.head
        while True:
            print(current.data, end=" -> ")
            current = current.next
            if current == self.head:
                break
        print()


if __name__ == "__main__":
    circular_linked_list = SinglyCircularLinkedList()

    # Insert elements into the circular linked list
    circular_linked_list.insert(1)
    circular_linked_list.insert(2)
    circular_linked_list.insert(3)
    circular_linked_list.insert(4)

    # Display the circular linked list
    print("Circular Linked List:")
    circular_linked_list.display()
