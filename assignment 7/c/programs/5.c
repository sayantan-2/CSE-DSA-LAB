#include <stdio.h>

#define MAX_SIZE 100

int deque[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the deque is empty
int is_empty()
{
    return front == -1;
}

// Function to check if the deque is full
int is_full()
{
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

// Function to insert an element at the front of the deque
void insert_front(int item)
{
    if (is_full())
    {
        printf("Deque is full. Cannot insert.\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX_SIZE - 1;
    }
    else
    {
        front--;
    }
    deque[front] = item;
    printf("Inserted %d at the front.\n", item);
}

// Function to insert an element at the rear of the deque
void insert_rear(int item)
{
    if (is_full())
    {
        printf("Deque is full. Cannot insert.\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX_SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = item;
    printf("Inserted %d at the rear.\n", item);
}

// Function to delete an element from the front of the deque
void delete_front()
{
    if (is_empty())
    {
        printf("Deque is empty. Cannot delete.\n");
        return;
    }
    int item = deque[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    printf("Deleted %d from the front.\n", item);
}

// Function to delete an element from the rear of the deque
void delete_rear()
{
    if (is_empty())
    {
        printf("Deque is empty. Cannot delete.\n");
        return;
    }
    int item = deque[rear];
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX_SIZE - 1;
    }
    else
    {
        rear--;
    }
    printf("Deleted %d from the rear.\n", item);
}

// Function to display the contents of the deque
void display()
{
    if (is_empty())
    {
        printf("Deque is empty.\n");
        return;
    }
    int i = front;
    printf("Deque: ");
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
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
    int choice, item;
    printf("\n1. Insert at front\n");
    printf("2. Insert at rear\n");
    printf("3. Delete from front\n");
    printf("4. Delete from rear\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert at front: ");
            scanf("%d", &item);
            insert_front(item);
            break;
        case 2:
            printf("Enter element to insert at rear: ");
            scanf("%d", &item);
            insert_rear(item);
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
