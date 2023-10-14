class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.value = key


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        self.root = self._insert_recursive(self.root, value)

    def _insert_recursive(self, current_node, value):
        if current_node is None:
            return Node(value)
        if value < current_node.value:
            current_node.left = self._insert_recursive(current_node.left, value)
        elif value > current_node.value:
            current_node.right = self._insert_recursive(current_node.right, value)
        return current_node

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
    tree = BinarySearchTree()
    tree.insert(10)
    tree.insert(5)
    tree.insert(15)
    tree.insert(3)
    tree.insert(7)
    tree.insert(12)
    tree.insert(18)

    print("Inorder Traversal:", tree.inorder_traversal())
    print("Searching for 7:", tree.search(7))
    print("Searching for 8:", tree.search(8))
