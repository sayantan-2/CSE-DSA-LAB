#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary search tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform in-order traversal of the binary search tree
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    // Input numbers to be sorted
    int numbers[] = {50, 30, 20, 40, 70, 60, 80};
    int numCount = sizeof(numbers) / sizeof(numbers[0]);

    // Insert numbers into the binary search tree
    for (int i = 0; i < numCount; i++)
    {
        root = insert(root, numbers[i]);
    }

    // Perform in-order traversal to display the sorted numbers
    printf("Sorted numbers: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
