#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left, *right;
    int leftTag, rightTag;
    int data;
};

struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = item;
    return temp;
}

void makeEmpty(struct Node *node)
{
    if (node != NULL)
    {
        makeEmpty(node->left);
        makeEmpty(node->right);
        free(node);
    }
}

void insert(struct Node **node, int data)
{
    if (*node == NULL)
    {
        *node = newNode(data);
    }
    else if (data <= (*node)->data)
    {
        insert(&((*node)->left), data);
        (*node)->leftTag = 1;
    }
    else
    {
        insert(&((*node)->right), data);
        (*node)->rightTag = 1;
    }
}

void inOrder(struct Node *node)
{
    if (node != NULL)
    {
        if (node->leftTag == 1)
            inOrder(node->left);
        printf("%d ", node->data);
        if (node->rightTag == 1)
            inOrder(node->right);
    }
}

int main()
{
    struct Node *root = NULL;

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal of the given tree \n");
    inOrder(root);

    makeEmpty(root);

    return 0;
}
