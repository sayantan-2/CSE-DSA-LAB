#include <stdio.h>
#include <stdlib.h>
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

int main()
{
    char expression[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", expression);
    int length = strlen(expression);
    for (int i = 0; i < length; i++)
    {
        if (expression[i] == '(')
        {
            push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            if (pop() == -1)
            {
                printf("Unbalanced parentheses\n");
                return 0;
            }
        }
    }
    if (top == -1)
    {
        printf("Balanced parentheses\n");
    }
    else
    {
        printf("Unbalanced parentheses\n");
    }
    return 0;
}
