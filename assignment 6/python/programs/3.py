class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def is_empty(self):
        return len(self.items) == 0


def check_parentheses(string):
    stack = Stack()
    for character in string:
        if character == "(":
            stack.push(character)
        elif character == ")":
            if stack.is_empty():
                return False
            else:
                stack.pop()

    return stack.is_empty()


# Example usage
string = input("Enter a string: ")
if check_parentheses(string):
    print("The number of opening and closing parentheses in the string are equal.")
else:
    print("The number of opening and closing parentheses in the string are not equal.")
