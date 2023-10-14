class Stack:
    def __init__(self):
        self.stack = []

    # Use list append method to push element in stack
    def push(self, item):
        self.stack.append(item)

    # Use list pop method to pop element from stack
    def pop(self):
        if len(self.stack) < 1:
            return None
        return self.stack.pop()

    # Use peek to look at the top of the stack without removing an element
    def peek(self):
        if not self.stack:
            return None
        return self.stack[-1]

    # Check if the stack is empty
    def is_empty(self):
        return len(self.stack) == 0

# Test the Stack class
s = Stack()
s.push("A")
s.push("B")
s.push("C")
print(s.pop())
print(s.peek())
