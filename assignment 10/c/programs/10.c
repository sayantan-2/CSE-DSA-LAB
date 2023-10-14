#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

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
    bool *visited;
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
    graph->visited = (bool *)malloc(numVertices * sizeof(bool));

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

// Recursive function for DFS traversal
void DFS(struct Graph *graph, int vertex)
{
    graph->visited[vertex] = true;
    printf("%d ", vertex);

    struct Node *temp = graph->adjacencyList[vertex];
    while (temp != NULL)
    {
        int neighbor = temp->data;
        if (!graph->visited[neighbor])
        {
            DFS(graph, neighbor);
        }
        temp = temp->next;
    }
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

    printf("Depth-First Search starting from vertex 0: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}
