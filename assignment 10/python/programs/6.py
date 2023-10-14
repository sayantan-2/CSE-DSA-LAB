class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.value = key


def mirror_bst(root):
    if root is None:
        return None

    # Swap left and right subtrees
    root.left, root.right = root.right, root.left

    # Recursively mirror the left and right subtrees
    mirror_bst(root.left)
    mirror_bst(root.right)

    return root


def inorder_traversal(node):
    if node:
        inorder_traversal(node.left)
        print(node.value, end=" ")
        inorder_traversal(node.right)


# Example usage:
if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    print("Original BST:")
    inorder_traversal(root)
    print("\n")

    mirrored_root = mirror_bst(root)

    print("Mirror Image BST:")
    inorder_traversal(mirrored_root)
