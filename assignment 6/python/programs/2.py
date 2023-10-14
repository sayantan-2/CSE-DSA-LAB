class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.head = None

    # The push operation is implemented by inserting an element at the beginning of the linked list
    def push(self, data):
        if self.head is None:
            self.head = Node(data)
        else:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node

    # The pop operation is implemented by deleting an element from the beginning of the linked list
    def pop(self):
        if self.head is None:
            return None
        else:
            popped_node = self.head
            self.head = self.head.next
            popped_node.next = None
            return popped_node.data


# Test the Stack class
s = Stack()
s.push("A")
s.push("B")
s.push("C")
print(s.pop())
