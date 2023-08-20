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

struct Node *swapPairs(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct Node *newHead = head->next; // New head after swapping
    struct Node *prev = NULL;

    while (head != NULL && head->next != NULL)
    {
        struct Node *nextNode = head->next->next; // Save the next pair

        // Swap the current pair
        head->next->next = head;
        if (prev != NULL)
        {
            prev->next = head->next;
        }
        head->next = nextNode;

        // Move pointers forward
        prev = head;
        head = nextNode;
    }

    return newHead;
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

    head = swapPairs(head);

    printf("List after Pairwise Swapping: ");
    printList(head);

    return 0;
}
