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

void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main()
{
    int n = 3;               // number of disks
    hanoi(n, 'A', 'C', 'B'); // A, B and C are the name of rods
    return 0;
}
