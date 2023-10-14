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

    def inorder_traversal(self):
        return self._inorder_traversal_recursive(self.root, [])

    def _inorder_traversal_recursive(self, current_node, result):
        if current_node:
            result = self._inorder_traversal_recursive(current_node.left, result)
            result.append(current_node.value)
            result = self._inorder_traversal_recursive(current_node.right, result)
        return result


def sort_numbers_using_bst(numbers):
    tree = BinarySearchTree()
    for number in numbers:
        tree.insert(number)
    return tree.inorder_traversal()


# Example usage:
if __name__ == "__main__":
    numbers = [12, 4, 7, 2, 14, 9, 3, 17]
    sorted_numbers = sort_numbers_using_bst(numbers)
    print("Sorted Numbers:", sorted_numbers)
