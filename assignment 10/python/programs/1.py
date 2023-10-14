class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.value = key

class BinaryTree:
    def __init__(self, root):
        self.root = Node(root)

    def insert(self, value):
        self._insert_recursive(self.root, value)

    def _insert_recursive(self, current_node, value):
        if value < current_node.value:
            if current_node.left is None:
                current_node.left = Node(value)
            else:
                self._insert_recursive(current_node.left, value)
        elif value > current_node.value:
            if current_node.right is None:
                current_node.right = Node(value)
            else:
                self._insert_recursive(current_node.right, value)

    def search(self, value):
        return self._search_recursive(self.root, value)

    def _search_recursive(self, current_node, value):
        if current_node is None:
            return False
        if current_node.value == value:
            return True
        if value < current_node.value:
            return self._search_recursive(current_node.left, value)
        else:
            return self._search_recursive(current_node.right, value)

    def inorder_traversal(self):
        return self._inorder_traversal_recursive(self.root, [])

    def _inorder_traversal_recursive(self, current_node, result):
        if current_node:
            result = self._inorder_traversal_recursive(current_node.left, result)
            result.append(current_node.value)
            result = self._inorder_traversal_recursive(current_node.right, result)
        return result

# Example usage:
if __name__ == "__main__":
    tree = BinaryTree(10)
    tree.insert(5)
    tree.insert(15)
    tree.insert(3)
    tree.insert(7)
    tree.insert(12)
    tree.insert(18)

    print("Inorder Traversal:", tree.inorder_traversal())
    print("Searching for 7:", tree.search(7))
    print("Searching for 8:", tree.search(8))
