#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node
{
    char data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(char data)
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
struct Node *insertAtEnd(struct Node *head, char data)
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

// Function to remove a character from the doubly linked list
struct Node *removeCharacter(struct Node *head, char target)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *current = head;

    do
    {
        if (current->data == target)
        {
            // If the node to be removed is the head node
            if (current == head)
            {
                head = head->next;
                head->prev = current->prev;
                current->prev->next = head;
                free(current);
                current = head; // Move to the next node
            }
            else
            {
                struct Node *temp = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current = current->next; // Move to the next node
                free(temp);
            }
        }
        else
        {
            current = current->next;
        }
    } while (current != head);

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

    struct Node *current = head;

    do
    {
        printf("%c -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Initialize a predefined doubly linked list with characters
    head = insertAtEnd(head, 'A');
    head = insertAtEnd(head, 'B');
    head = insertAtEnd(head, 'C');
    head = insertAtEnd(head, 'A');
    head = insertAtEnd(head, 'D');
    head = insertAtEnd(head, 'E');

    printf("Initial Doubly Linked List: ");
    display(head);

    char target;
    printf("Enter the character to remove: ");
    scanf(" %c", &target); // Note the space before %c to consume the newline character

    // Remove the specified character
    head = removeCharacter(head, target);

    printf("Updated Doubly Linked List: ");
    display(head);

    return 0;
}
