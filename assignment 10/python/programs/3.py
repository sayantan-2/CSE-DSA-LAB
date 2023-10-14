class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def is_full_binary_tree(root):
    if not root:
        return True

    if not root.left and not root.right:
        return True

    if root.left and root.right:
        return is_full_binary_tree(root.left) and is_full_binary_tree(root.right)

    return False

def is_complete_binary_tree(root):
    if not root:
        return True

    queue = [root]
    is_last_level = False

    while queue:
        current_node = queue.pop(0)

        if current_node is None:
            is_last_level = True
        else:
            if is_last_level:
                return False

            queue.append(current_node.left)
            queue.append(current_node.right)

    return True

# Example usage:
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)

if is_full_binary_tree(root):
    print("The tree is a full binary tree.")
else:
    print("The tree is not a full binary tree.")

if is_complete_binary_tree(root):
    print("The tree is a complete binary tree.")
else:
    print("The tree is not a complete binary tree.")
