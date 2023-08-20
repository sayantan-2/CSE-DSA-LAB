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

struct Node *leftShiftLinkedList(struct Node *head, int k)
{
    if (head == NULL || k == 0)
    {
        return head;
    }

    struct Node *current = head;
    int length = 0;

    // Count the number of nodes in the linked list
    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    // Normalize the value of k
    k = k % length;

    if (k == 0)
    {
        return head;
    }

    current = head;

    // Find the (N - k)th node
    for (int i = 1; i < length - k; i++)
    {
        current = current->next;
    }

    struct Node *newHead = current->next;
    current->next = NULL;

    // Traverse to the end of the newHead list
    struct Node *temp = newHead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Update the end of the newHead list to point to the original head
    temp->next = head;

    return newHead;
}

int main()
{
    struct Node *head = NULL;
    int num, data, k;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &num);

    printf("Enter the elements:\n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data);
        head = insert(head, data);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Original Linked List: ");
    printList(head);

    struct Node *shiftedHead = leftShiftLinkedList(head, k);

    printf("Left-Shifted Linked List: ");
    printList(shiftedHead);

    return 0;
}