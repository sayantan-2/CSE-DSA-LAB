#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Queue data structure for BFS
struct Queue
{
    int items[MAX_NODES];
    int front;
    int rear;
};

// Function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue *queue)
{
    return (queue->front == -1);
}

// Function to add an item to the queue
void enqueue(struct Queue *queue, int item)
{
    if (queue->rear == MAX_NODES - 1)
    {
        printf("Queue is full.\n");
    }
    else
    {
        if (queue->front == -1)
        {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
    }
}

// Function to remove an item from the queue
int dequeue(struct Queue *queue)
{
    int item;
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        item = -1;
    }
    else
    {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
        {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Structure for a graph node
struct Node
{
    int data;
    struct Node *next;
};

// Structure for a graph
struct Graph
{
    int numVertices;
    struct Node **adjacencyList;
};

// Function to create a new graph node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (struct Node **)malloc(numVertices * sizeof(struct Node *));

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function to perform BFS traversal of the graph
void BFS(struct Graph *graph, int startVertex)
{
    bool visited[MAX_NODES] = {false}; // Keep track of visited vertices
    struct Queue *queue = createQueue();

    visited[startVertex] = true;
    enqueue(queue, startVertex);

    printf("Breadth-First Search starting from vertex %d: ", startVertex);

    while (!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node *temp = graph->adjacencyList[currentVertex];
        while (temp)
        {
            int neighbor = temp->data;
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                enqueue(queue, neighbor);
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

int main()
{
    struct Graph *graph = createGraph(7);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);

    // Perform BFS traversal starting from vertex 0
    BFS(graph, 0);

    return 0;
}
