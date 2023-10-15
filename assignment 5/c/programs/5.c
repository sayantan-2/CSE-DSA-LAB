#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to delete a node at a specific position in the doubly linked list
struct Node *deleteAtPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if (position <= 0)
    {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 1)
    {
        struct Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    struct Node *current = head;
    int count = 1;

    // Find the node to be deleted
    while (count < position && current != NULL)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        printf("Position out of range.\n");
        return head;
    }

    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    free(current);
    return head;
}

// Function to display the doubly linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    // Initialize a predefined doubly linked list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Initial Doubly Linked List: ");
    display(head);

    int data, position;

    // Insertion
    printf("\nEnter data to insert at the end: ");
    scanf("%d", &data);
    head = insertAtEnd(head, data);

    // Display the list after insertion
    display(head);

    // Deletion
    printf("\nEnter position to delete: ");
    scanf("%d", &position);
    head = deleteAtPosition(head, position);

    // Display the list after deletion
    display(head);

    return 0;
}
