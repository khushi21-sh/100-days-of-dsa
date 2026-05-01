#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
    int* recStack;
} Graph;

// Create node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));
    graph->recStack = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
        graph->recStack[i] = 0;
    }

    return graph;
}

// Add edge (directed)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// DFS cycle detection
int hasCycleDFS(Graph* graph, int v) {
    graph->visited[v] = 1;
    graph->recStack[v] = 1;

    Node* temp = graph->adjLists[v];

    while (temp) {
        int adj = temp->vertex;

        if (!graph->visited[adj]) {
            if (hasCycleDFS(graph, adj))
                return 1;
        }
        else if (graph->recStack[adj]) {
            return 1; // Cycle found
        }

        temp = temp->next;
    }

    graph->recStack[v] = 0; // remove from recursion stack
    return 0;
}

// Check entire graph
int containsCycle(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            if (hasCycleDFS(graph, i))
                return 1;
        }
    }
    return 0;
}

// Driver
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (containsCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}