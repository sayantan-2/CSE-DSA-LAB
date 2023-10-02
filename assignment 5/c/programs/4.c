#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Circular link to itself
        return newNode;
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    newNode->next = head;
    last->next = newNode;
    return head;
}

// Function to delete a node with a specific data value from the circular linked list
struct Node* deleteElement(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    // Find the node to be deleted
    do {
        if (current->data == key) {
            if (previous == NULL) {
                // If the node to be deleted is the head node
                struct Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
                free(current);
                return head;
            } else {
                previous->next = current->next;
                free(current);
                return head;
            }
        }
        previous = current;
        current = current->next;
    } while (current != head);

    printf("Element not found in the list.\n");
    return head;
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Initialize a predefined circular linked list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Initial Circular Linked List: ");
    display(head);

    int data;

    // First time for insertion
    printf("\nEnter data to insert: ");
    scanf("%d", &data);
    head = insertAtEnd(head, data);
    printf("Updated Circular Linked List: ");
    display(head);

    // Second time for deletion
    printf("\nEnter data to delete: ");
    scanf("%d", &data);
    head = deleteElement(head, data);
    printf("Updated Circular Linked List: ");
    display(head);

    return 0;
}
