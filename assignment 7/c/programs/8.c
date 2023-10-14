#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the stack
typedef struct
{
    int array[MAX_SIZE];
    int top;
} Stack;

// Function to initialize a stack
void initialize(Stack *stack)
{
    stack->top = -1;
}

// Function to check if a stack is empty
int is_empty(Stack *stack)
{
    return stack->top == -1;
}

// Function to check if a stack is full
int is_full(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int data)
{
    if (is_full(stack))
    {
        printf("Stack overflow. Cannot push.\n");
        return;
    }
    stack->array[++stack->top] = data;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack underflow. Cannot pop.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Define a structure for the queue using two stacks
typedef struct
{
    Stack stack1; // for enqueue operations
    Stack stack2; // for dequeue operations
} Queue;

// Function to initialize a queue
void initializeQueue(Queue *queue)
{
    initialize(&queue->stack1);
    initialize(&queue->stack2);
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int data)
{
    push(&queue->stack1, data);
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue)
{
    if (is_empty(&queue->stack1) && is_empty(&queue->stack2))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    if (is_empty(&queue->stack2))
    {
        // Transfer elements from stack1 to stack2
        while (!is_empty(&queue->stack1))
        {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }

    return pop(&queue->stack2);
}

int main()
{
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Dequeued: %d\n", dequeue(&queue)); // Dequeued: 10
    printf("Dequeued: %d\n", dequeue(&queue)); // Dequeued: 20

    enqueue(&queue, 40);
    printf("Dequeued: %d\n", dequeue(&queue)); // Dequeued: 30
    printf("Dequeued: %d\n", dequeue(&queue)); // Dequeued: 40

    return 0;
}
