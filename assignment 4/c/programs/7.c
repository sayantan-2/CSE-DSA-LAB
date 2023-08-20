#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *insert(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link

        // Move the pointers forward
        prev = current;
        current = next;
    }

    return prev; // New head after reversal
}

int main()
{
    struct Node *head = NULL;
    int num, data;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &num);

    printf("Enter the elements:\n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data);
        head = insert(head, data);
    }

    printf("Original List: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
