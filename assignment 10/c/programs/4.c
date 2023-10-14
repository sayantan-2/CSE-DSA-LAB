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

   // Insert elements into the binary search tree
   root = insert(root, 50);
   root = insert(root, 30);
   root = insert(root, 20);
   root = insert(root, 40);
   root = insert(root, 70);
   root = insert(root, 60);
   root = insert(root, 80);

   // Perform in-order traversal to display the elements in ascending order
   printf("In-order traversal: ");
   inOrderTraversal(root);
   printf("\n");

   return 0;
}
