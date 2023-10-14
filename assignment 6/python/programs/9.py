class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def is_empty(self):
        return len(self.items) == 0


def reverse_string(string):
    stack = Stack()
    for character in string:
        stack.push(character)

    reversed_string = ""
    while not stack.is_empty():
        reversed_string += stack.pop()

    return reversed_string


# Example usage
string = input("Enter a string: ")
print("Original string:", string)
print("Reversed string:", reverse_string(string))
