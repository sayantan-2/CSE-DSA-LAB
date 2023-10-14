#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front, *rear, *temp;

void enq(int data);
void deq();
void display();

int main()
{
    int choice, data;
    front = rear = NULL;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to be enqueued: ");
            scanf("%d", &data);
            enq(data);
            break;
        case 2:
            deq();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void enq(int data)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    if (front == NULL)
    {
        front = rear = temp;
        rear->next = front;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

void deq()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else if (front == rear)
    {
        printf("Dequeued element: %d\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        printf("Dequeued element: %d\n", temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        temp = front;

        while (temp->next != front)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("%d ", temp->data);
    }
}
