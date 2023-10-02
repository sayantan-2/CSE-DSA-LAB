#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

void insertEnd(Node** start, int value) {
    if (*start == NULL) {
        Node* new_node = newNode(value);
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }

    Node *last = (*start)->prev;

    Node* new_node = newNode(value);

    new_node->next = *start;

    (*start)->prev = new_node;

    new_node->prev = last;

    last->next = new_node;
}

void display(Node* start) {
    Node* temp = start;

    while (temp->next != start) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

int main() {
    Node* start = NULL;

    insertEnd(&start, 5);
    insertEnd(&start, 4);
    insertEnd(&start, 3);
    insertEnd(&start, 2);
    insertEnd(&start, 1);

    printf("Circular doubly linked list: ");
    display(start);

    return 0;
}
