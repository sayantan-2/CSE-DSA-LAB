#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char element)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = element;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void reverseString(char *string)
{
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        push(string[i]);
    }
    for (int i = 0; i < length; i++)
    {
        string[i] = pop();
    }
}

int main()
{
    char string[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", string);
    reverseString(string);
    printf("The reversed string is: %s\n", string);
    return 0;
}
