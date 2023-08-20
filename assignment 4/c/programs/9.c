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

int hasLoop(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return 1; // Loop detected
        }
    }

    return 0; // No loop
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

    // Creating a loop for demonstration purposes
    if (num >= 3)
    {
        struct Node *temp = head;
        for (int i = 0; i < num - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = head;
    }

    if (hasLoop(head))
    {
        printf("The linked list contains a loop.\n");
    }
    else
    {
        printf("The linked list does not contain a loop.\n");
    }

    return 0;
}
