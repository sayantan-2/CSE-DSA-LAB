# Define a class to represent a node in the linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Function to create a new node with the given data and insert it at the end of the list
def insert_at_end(head, data):
    new_node = Node(data)
    if head is None:
        head = new_node
        return head
    current = head
    while current.next is not None:
        current = current.next
    current.next = new_node
    return head


# Function to print the elements of the linked list
def print_list(head):
    current = head
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()


if __name__ == "__main__":
    # Create an empty linked list
    head = None

    # Insert elements into the list
    N = int(input("Enter the number of elements to insert: "))
    for i in range(N):
        data = int(input(f"Enter element {i + 1}: "))
        head = insert_at_end(head, data)

    # Print the elements of the list
    print_list(head)
