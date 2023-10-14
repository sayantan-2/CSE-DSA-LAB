#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top1 = -1;
int top2 = MAX_SIZE;

void push(int element, int stackNumber)
{
    if (top1 == top2 - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    if (stackNumber == 1)
    {
        stack[++top1] = element;
    }
    else if (stackNumber == 2)
    {
        stack[--top2] = element;
    }
    else
    {
        printf("Invalid stack number\n");
    }
}

int pop(int stackNumber)
{
    if (stackNumber == 1)
    {
        if (top1 == -1)
        {
            printf("Stack underflow\n");
            return -1;
        }
        return stack[top1--];
    }
    else if (stackNumber == 2)
    {
        if (top2 == MAX_SIZE)
        {
            printf("Stack underflow\n");
            return -1;
        }
        return stack[top2++];
    }
    else
    {
        printf("Invalid stack number\n");
        return -1;
    }
}

int main()
{
    push(10, 1);
    push(20, 2);
    push(30, 2);
    push(40, 1);
    printf("%d\n", pop(1));
    printf("%d\n", pop(2));
    printf("%d\n", pop(2));
    printf("%d\n", pop(1));
    printf("%d\n", pop(1));
    return 0;
}
