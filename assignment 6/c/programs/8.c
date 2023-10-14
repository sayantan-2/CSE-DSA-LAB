#include <stdio.h>
#include <stdlib.h>

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

void decimalToBinary(int decimalNumber)
{
    while (decimalNumber != 0)
    {
        int remainder = decimalNumber % 2;
        push(remainder);
        decimalNumber /= 2;
    }
    while (top != -1)
    {
        printf("%d", pop());
    }
}

int main()
{
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    printf("The binary equivalent is: ");
    decimalToBinary(decimalNumber);
    printf("\n");
    return 0;
}
