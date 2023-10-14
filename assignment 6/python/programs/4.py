def infix_to_postfix(expression):
    # Define the set of operators and their priorities
    operators = set(['+', '-', '*', '/', '(', ')', '^'])
    priority = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}

    # Initialize an empty stack and output string
    stack = []
    output = ''

    # Iterate through each character in the expression
    for character in expression:
        if character not in operators:
            # If the character is an operand, add it to the output string
            output += character
        elif character == '(':
            # If the character is an opening parenthesis, push it onto the stack
            stack.append('(')
        elif character == ')':
            # If the character is a closing parenthesis, pop operators from the stack and add them to the output string until an opening parenthesis is found
            while stack and stack[-1] != '(':
                output += stack.pop()
            stack.pop()
        else:
            # If the character is an operator, pop operators from the stack and add them to the output string until an operator with lower priority is found
            while stack and stack[-1] != '(' and priority[character] <= priority[stack[-1]]:
                output += stack.pop()
            stack.append(character)

    # Pop any remaining operators from the stack and add them to the output string
    while stack:
        output += stack.pop()

    return output

# Example usage
expression = input('Enter an infix expression: ')
print('Infix expression:', expression)
print('Postfix expression:', infix_to_postfix(expression))
