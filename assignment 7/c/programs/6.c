#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
    int data;
    int priority;
} QueueElement;

QueueElement priorityQueue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the priority queue is empty
int is_empty()
{
    return front == -1;
}

// Function to check if the priority queue is full
int is_full()
{
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

// Function to insert an element with priority into the priority queue
void enqueue(int data, int priority)
{
    if (is_full())
    {
        printf("Priority queue is full. Cannot insert.\n");
        return;
    }

    QueueElement newItem;
    newItem.data = data;
    newItem.priority = priority;

    if (is_empty())
    {
        front = rear = 0;
        priorityQueue[rear] = newItem;
    }
    else
    {
        int i;
        for (i = rear; i >= front; i--)
        {
            if (priorityQueue[i].priority > priority)
            {
                priorityQueue[i + 1] = priorityQueue[i];
            }
            else
            {
                break;
            }
        }
        priorityQueue[i + 1] = newItem;
        rear++;
    }

    printf("Inserted %d with priority %d.\n", data, priority);
}

// Function to dequeue (remove) the highest-priority element
void dequeue()
{
    if (is_empty())
    {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return;
    }

    int data = priorityQueue[front].data;
    int priority = priorityQueue[front].priority;

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }

    printf("Dequeued %d with priority %d.\n", data, priority);
}

// Function to display the contents of the priority queue
void display()
{
    if (is_empty())
    {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("(%d, %d) ", priorityQueue[i].data, priorityQueue[i].priority);
    }
    printf("\n");
}

int main()
{
    int choice, data, priority;
    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            enqueue(data, priority);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
