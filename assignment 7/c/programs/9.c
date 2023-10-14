#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the queue
typedef struct
{
    int array[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize a queue
void initialize(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int is_empty(Queue *queue)
{
    return queue->front == -1;
}

// Function to check if the queue is full
int is_full(Queue *queue)
{
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1);
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int data)
{
    if (is_full(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (queue->front == -1)
    {
        queue->front = 0;
    }
    if (queue->rear == MAX_SIZE - 1)
    {
        queue->rear = 0;
    }
    else
    {
        queue->rear++;
    }

    queue->array[queue->rear] = data;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = queue->array[queue->front];

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else if (queue->front == MAX_SIZE - 1)
    {
        queue->front = 0;
    }
    else
    {
        queue->front++;
    }

    return data;
}

// Function to reverse a queue using an additional stack
void reverseQueue(Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty. Cannot reverse.\n");
        return;
    }

    int stack[MAX_SIZE];
    int top = -1;

    while (!is_empty(queue))
    {
        stack[++top] = dequeue(queue);
    }

    while (top >= 0)
    {
        enqueue(queue, stack[top--]);
    }
}

// Function to display the contents of the queue
void display(Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    printf("Queue: ");
    while (1)
    {
        printf("%d ", queue->array[i]);
        if (i == queue->rear)
            break;
        if (i == MAX_SIZE - 1)
            i = 0;
        else
            i++;
    }
    printf("\n");
}

int main()
{
    Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Original Queue:\n");
    display(&queue);

    reverseQueue(&queue);

    printf("Reversed Queue:\n");
    display(&queue);

    return 0;
}
