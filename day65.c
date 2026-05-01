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

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge (undirected)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS cycle detection
int hasCycleDFS(Graph* graph, int vertex, int parent) {
    graph->visited[vertex] = 1;

    Node* temp = graph->adjLists[vertex];

    while (temp) {
        int adj = temp->vertex;

        if (!graph->visited[adj]) {
            if (hasCycleDFS(graph, adj, vertex))
                return 1;
        }
        else if (adj != parent) {
            return 1; // Cycle found
        }

        temp = temp->next;
    }

    return 0;
}

// Check cycle in entire graph
int containsCycle(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            if (hasCycleDFS(graph, i, -1))
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