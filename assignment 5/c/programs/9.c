#include<stdio.h>
#include<stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to insert at the end
void insert(struct Node** start, int value)
{
    // If the list is empty, create a single node
    if (*start == NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = new_node->prev = NULL;
        *start = new_node;
    } else {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        struct Node* last = *start;
        new_node->data = value;
        new_node->next = NULL;
        while (last->next != NULL)
            last = last->next;
        last->next = new_node;
        new_node->prev = last;
    }
}

// Function to print nodes in a given doubly linked list
void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to reverse a doubly linked list
struct Node* reverse(struct Node* node)
{
    struct Node* temp = NULL;
    struct Node* current = node;

    // Swap next and prev for all nodes of doubly linked list
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Before changing the head, check for the cases like empty list and list with only one node
    if(temp != NULL )
        node = temp->prev;
    return node;
}

// Driver program to test above
int main()
{
    struct Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);

    printf("Original Doubly linked list:\n");
    printList(head);

    head = reverse(head);

    printf("\nDoubly linked list after reversal:\n");
    printList(head);

    return 0;
}
