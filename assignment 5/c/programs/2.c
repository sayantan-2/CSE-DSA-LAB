#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void insertAtBeginning(Node **head_ref, int data)
{
    Node *node = newNode(data);
    if (*head_ref == NULL)
    {
        *head_ref = node;
        return;
    }
    node->next = *head_ref;
    (*head_ref)->prev = node;
    *head_ref = node;
}

void printList(Node *node)
{
    Node *last;
    printf("Traversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

int main()
{
    Node *head = NULL;
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 4);

    printf("Created DLL is: \n");
    printList(head);

    return 0;
}
