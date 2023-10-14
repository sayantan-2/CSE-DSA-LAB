#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int element)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = element;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix(char *postfixExpression)
{
    int length = strlen(postfixExpression);
    for (int i = 0; i < length; i++)
    {
        char currentCharacter = postfixExpression[i];
        if (isdigit(currentCharacter))
        {
            push(currentCharacter - '0');
        }
        else
        {
            int operand2 = pop();
            int operand1 = pop();
            switch (currentCharacter)
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            case '%':
                push(operand1 % operand2);
                break;
            default:
                printf("Invalid operator\n");
                return -1;
            }
        }
    }
    return pop();
}

int main()
{
    char postfixExpression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);
    int result = evaluatePostfix(postfixExpression);
    if (result != -1)
    {
        printf("The result is: %d\n", result);
    }
    return 0;
}
