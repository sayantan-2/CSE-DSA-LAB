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

// Function to mirror a binary search tree
struct Node *mirrorBST(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    // Swap the left and right subtrees
    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirrorBST(root->left);
    mirrorBST(root->right);

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

    // Input numbers to create the original BST
    int numbers[] = {50, 30, 20, 40, 70, 60, 80};
    int numCount = sizeof(numbers) / sizeof(numbers[0]);

    // Insert numbers into the binary search tree
    for (int i = 0; i < numCount; i++)
    {
        root = insert(root, numbers[i]);
    }

    // Mirror the BST
    struct Node *mirroredRoot = mirrorBST(root);

    // Perform in-order traversal to display the mirror image
    printf("In-order traversal of the mirror image: ");
    inOrderTraversal(mirroredRoot);
    printf("\n");

    return 0;
}
