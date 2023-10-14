#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the binary tree
typedef struct Node
{
    char *data;
    struct Node *left;
    struct Node *right;
} Node;

// Define a structure for the queue
typedef struct QueueNode
{
    Node *data;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Function to create a new queue
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue *queue)
{
    return queue->front == NULL;
}

// Function to enqueue a node into the queue
void enqueue(Queue *queue, Node *node)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = node;
    newNode->next = NULL;
    if (isQueueEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a node from the queue
Node *dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        return NULL;
    }
    QueueNode *temp = queue->front;
    Node *node = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return node;
}

// Function to generate binary numbers from 1 to n
void generateBinaryNumbers(int n)
{
    if (n < 1)
    {
        return;
    }

    Queue *queue = createQueue();
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = "1";
    root->left = root->right = NULL;

    enqueue(queue, root);

    for (int i = 0; i < n; i++)
    {
        Node *current = dequeue(queue);
        printf("%s\n", current->data);

        Node *left = (Node *)malloc(sizeof(Node));
        left->data = (char *)malloc(2 * sizeof(char));
        sprintf(left->data, "%s0", current->data);
        left->left = left->right = NULL;
        current->left = left;
        enqueue(queue, left);

        Node *right = (Node *)malloc(sizeof(Node));
        right->data = (char *)malloc(2 * sizeof(char));
        sprintf(right->data, "%s1", current->data);
        right->left = right->right = NULL;
        current->right = right;
        enqueue(queue, right);
    }

    // Clean up the queue and free allocated memory
    while (!isQueueEmpty(queue))
    {
        Node *node = dequeue(queue);
        free(node->data);
        free(node);
    }
    free(queue);
}

int main()
{
    int n;
    printf("Enter a positive number (n): ");
    scanf("%d", &n);
    printf("Binary numbers from 1 to %d:\n", n);
    generateBinaryNumbers(n);
    return 0;
}
