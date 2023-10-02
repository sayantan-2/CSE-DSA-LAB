class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class DoublyLinkedListNode:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # Insert a node at the end of the doubly linked list
    def insert_at_end(self, data):
        new_node = DoublyLinkedListNode(data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node


def convert_binary_tree_to_doubly_linked_list(root, doubly_linked_list):
    if root is None:
        return

    # Recursively convert the left subtree
    convert_binary_tree_to_doubly_linked_list(root.left, doubly_linked_list)

    # Insert the current node into the doubly linked list
    doubly_linked_list.insert_at_end(root.data)

    # Recursively convert the right subtree
    convert_binary_tree_to_doubly_linked_list(root.right, doubly_linked_list)


if __name__ == "__main__":
    # Create a binary tree
    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(6)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)
    root.right.left = TreeNode(5)
    root.right.right = TreeNode(7)

    # Create an empty doubly linked list
    doubly_linked_list = DoublyLinkedList()

    # Convert the binary tree to a doubly linked list
    convert_binary_tree_to_doubly_linked_list(root, doubly_linked_list)

    # Display the doubly linked list
    current = doubly_linked_list.head
    while current:
        print(current.data, end=" <-> ")
        current = current.next
    print("None")
