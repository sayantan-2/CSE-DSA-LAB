#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void addNode(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = *head_ref;

    if (*head_ref != NULL)
    {
        while (last->next != *head_ref)
            last = last->next;
        last->next = new_node;
    }
    else
        new_node->next = new_node;

    *head_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

int main()
{
    struct Node *head = NULL;

    addNode(&head, 12);
    addNode(&head, 56);
    addNode(&head, 2);
    addNode(&head, 11);

    printf("Contents of Circular Linked List\n ");
    printList(head);

    return 0;
}
