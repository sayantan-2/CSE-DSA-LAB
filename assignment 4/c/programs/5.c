#include <stdio.h>
#include <malloc.h>

// Definition of a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
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

// Function to merge two sorted linked lists
struct Node *mergeSortedLists(struct Node *list1, struct Node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    struct Node *mergedList = NULL;
    if (list1->data < list2->data)
    {
        mergedList = list1;
        mergedList->next = mergeSortedLists(list1->next, list2);
    }
    else
    {
        mergedList = list2;
        mergedList->next = mergeSortedLists(list1, list2->next);
    }
    return mergedList;
}

// Function to print a linked list
void printList(struct Node *head)
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
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    int num1, num2, data;

    // Taking user input for the first sorted linked list
    printf("Enter the number of elements in the first sorted list: ");
    scanf("%d", &num1);
    printf("Enter the elements in ascending order:\n");
    for (int i = 0; i < num1; i++)
    {
        scanf("%d", &data);
        list1 = insert(list1, data);
    }

    // Taking user input for the second sorted linked list
    printf("Enter the number of elements in the second sorted list: ");
    scanf("%d", &num2);
    printf("Enter the elements in ascending order:\n");
    for (int i = 0; i < num2; i++)
    {
        scanf("%d", &data);
        list2 = insert(list2, data);
    }

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node *mergedList = mergeSortedLists(list1, list2);
    printf("Merged Sorted List: ");
    printList(mergedList);

    return 0;
}
