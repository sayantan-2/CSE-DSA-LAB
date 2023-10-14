def evaluate_postfix(expression):
    # Initialize an empty stack
    stack = []

    # Iterate through each character in the expression
    for character in expression:
        if character.isdigit():
            # If the character is a digit, push it onto the stack
            stack.append(int(character))
        else:
            # If the character is an operator, pop two operands from the stack and apply the operator
            operand2 = stack.pop()
            operand1 = stack.pop()
            if character == '+':
                result = operand1 + operand2
            elif character == '-':
                result = operand1 - operand2
            elif character == '*':
                result = operand1 * operand2
            elif character == '/':
                result = operand1 / operand2
            elif character == '^':
                result = operand1 ** operand2
            else:
                raise ValueError('Invalid operator')
            # Push the result onto the stack
            stack.append(result)

    # The final result is the only element left in the stack
    return stack[0]

# Example usage
expression = input('Enter a postfix expression: ')
print('Postfix expression:', expression)
print('Result:', evaluate_postfix(expression))
