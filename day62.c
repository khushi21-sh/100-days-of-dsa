#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;
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

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(Graph* graph, int src, int dest) {
    // Add dest to src
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add src to dest
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("%d: ", i);

        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
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

    printGraph(graph);

    return 0;
}                                                                           