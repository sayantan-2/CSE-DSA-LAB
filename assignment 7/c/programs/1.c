#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int element)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = element;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow\n");
        return -1;
    }
    return queue[front++];
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("%d dequeued from the queue\n", dequeue());
    printf("%d dequeued from the queue\n", dequeue());
    display();
    return 0;
}
