#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void BinaryTreeToDLL(struct node* root, struct node** head) {
    if (root == NULL) return;

    static struct node* prev = NULL;

    BinaryTreeToDLL(root->left, head);

    if (prev == NULL)
        *head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    BinaryTreeToDLL(root->right, head);
}

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->right;
    }
}

int main() {
    struct node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    struct node* head = NULL;
    BinaryTreeToDLL(root, &head);

    printList(head);

    return 0;
}
