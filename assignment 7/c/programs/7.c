#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue
typedef struct
{
    int *array;
    int front;
    int rear;
    unsigned capacity;
} Queue;

// Function to create a new queue
Queue *createQueue(unsigned capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(Queue *queue)
{
    return (queue->rear - queue->front + 1) == queue->capacity;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
    return queue->front > queue->rear;
}

// Function to enqueue an element to the queue
void enqueue(Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    queue->array[++queue->rear] = item;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    return queue->array[queue->front++];
}

// Function to implement a stack using two queues
typedef struct
{
    Queue *queue1;
    Queue *queue2;
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->queue1 = createQueue(100);
    stack->queue2 = createQueue(100);
    return stack;
}

void push(Stack *stack, int item)
{
    if (isEmpty(stack->queue1))
    {
        enqueue(stack->queue1, item);
        while (!isEmpty(stack->queue2))
        {
            enqueue(stack->queue1, dequeue(stack->queue2));
        }
    }
    else
    {
        enqueue(stack->queue2, item);
        while (!isEmpty(stack->queue1))
        {
            enqueue(stack->queue2, dequeue(stack->queue1));
        }
    }
}

int pop(Stack *stack)
{
    if (isEmpty(stack->queue1) && isEmpty(stack->queue2))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    if (!isEmpty(stack->queue1))
    {
        return dequeue(stack->queue1);
    }
    else
    {
        return dequeue(stack->queue2);
    }
}

int main()
{
    Stack *stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Popped: %d\n", pop(stack)); // Popped: 30
    printf("Popped: %d\n", pop(stack)); // Popped: 20

    push(stack, 40);
    printf("Popped: %d\n", pop(stack)); // Popped: 40

    return 0;
}
