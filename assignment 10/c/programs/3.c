#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a binary tree node
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

// Function to check if a binary tree is full
bool isFullTree(struct Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    // If a node has either 0 or 2 children, continue checking
    if ((root->left && root->right) || (!root->left && !root->right))
    {
        return isFullTree(root->left) && isFullTree(root->right);
    }
    else
    {
        return false;
    }
}

// Function to check if a binary tree is complete
bool isCompleteTree(struct Node *root, int index, int nodeCount)
{
    if (root == NULL)
    {
        return true;
    }

    if (index >= nodeCount)
    {
        return false;
    }

    return isCompleteTree(root->left, 2 * index + 1, nodeCount) &&
           isCompleteTree(root->right, 2 * index + 2, nodeCount);
}

int countNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int nodeCount = countNodes(root);

    if (isFullTree(root))
    {
        printf("The tree is a full binary tree.\n");
    }
    else
    {
        printf("The tree is not a full binary tree.\n");
    }

    if (isCompleteTree(root, 0, nodeCount))
    {
        printf("The tree is a complete binary tree.\n");
    }
    else
    {
        printf("The tree is not a complete binary tree.\n");
    }

    return 0;
}
