#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly circular linked list
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

// Function to insert a node at the end of the doubly circular linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;

    return head;
}

// Function to delete a node at a specific position in the doubly circular linked list
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

        if (head->next == head)
        {
            free(head);
            return NULL; // List becomes empty
        }

        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;

        free(temp);
        return head;
    }

    struct Node *current = head;
    int count = 1;

    // Find the node to be deleted
    while (count < position && current->next != head)
    {
        current = current->next;
        count++;
    }

    if (count < position)
    {
        printf("Position out of range.\n");
        return head;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current);
    return head;
}

// Function to display the doubly circular linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;

    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Initialize a predefined doubly circular linked list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Initial Doubly Circular Linked List: ");
    display(head);

    int data, position;

    // Insertion
    printf("\nEnter data to insert at the end: ");
    scanf("%d", &data);
    head = insertAtEnd(head, data);

    // Display the list after insertion
    printf("Updated Doubly Circular Linked List: ");
    display(head);

    // Deletion
    printf("\nEnter position to delete: ");
    scanf("%d", &position);
    head = deleteAtPosition(head, position);

    // Display the list after deletion
    printf("Final Doubly Circular Linked List: ");
    display(head);

    return 0;
}
