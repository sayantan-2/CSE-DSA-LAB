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

    # Divide the doubly linked list from the middle and rejoin in reverse
    def divide_and_reverse(self):
        if self.head is None:
            print("List is empty. Cannot divide and reverse.")
            return

        # Find the middle of the doubly linked list
        slow_ptr = self.head
        fast_ptr = self.head

        while fast_ptr.next is not None and fast_ptr.next.next is not None:
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next

        # Split the list into two halves
        second_half = slow_ptr.next
        slow_ptr.next = None
        second_half.prev = None

        # Reverse the second half
        current = second_half
        prev_node = None

        while current is not None:
            next_node = current.next
            current.next = prev_node
            current.prev = next_node
            prev_node = current
            current = next_node

        # Join the two halves
        current = self.head
        while current.next is not None:
            current = current.next
        current.next = prev_node
        prev_node.prev = current

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
    for data in [1, 2, 3, 4, 5, 6]:
        doubly_linked_list.insert_at_end(data)

    # Display the original doubly linked list
    print("Original Doubly Linked List:")
    doubly_linked_list.display()

    # Divide and reverse the doubly linked list
    doubly_linked_list.divide_and_reverse()

    # Display the doubly linked list after division and reversal
    print("Doubly Linked List After Division and Reversal:")
    doubly_linked_list.display()
