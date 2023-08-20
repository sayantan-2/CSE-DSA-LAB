#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node with the given data and insert it at the end of the list
void insert_at_end(struct Node **head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

// Function to print the elements of the linked list
void print_list(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    // Create an empty linked list
    struct Node *head = NULL;

    // Insert elements into the list
    int N, data;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert_at_end(&head, data);
    }

    // Print the elements of the list
    print_list(head);

    return 0;
}
