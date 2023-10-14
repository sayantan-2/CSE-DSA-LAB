#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
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
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
        rear = temp;
    }
}

void deq()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        temp = front;
        front = front->ptr;

        if (front == NULL)
        {
            rear = NULL;
        }

        printf("Dequeued element: %d\n", temp->info);
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

        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->ptr;
        }

        printf("\n");
    }
}
