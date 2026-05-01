#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Queue
typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int val) {
    q->items[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->items[q->front++];
}

// Graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* inDegree;
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
    graph->inDegree = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->inDegree[i] = 0;
    }

    return graph;
}

// Add edge (directed)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Increase in-degree of destination
    graph->inDegree[dest]++;
}

// Kahn's Algorithm
void topologicalSort(Graph* graph) {
    Queue q;
    initQueue(&q);

    // Step 1: push all nodes with in-degree 0
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->inDegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    int count = 0;

    // Step 2: process queue
    while (!isEmpty(&q)) {
        int curr = dequeue(&q);
        printf("%d ", curr);
        count++;

        Node* temp = graph->adjLists[curr];

        while (temp) {
            int adj = temp->vertex;
            graph->inDegree[adj]--;

            if (graph->inDegree[adj] == 0) {
                enqueue(&q, adj);
            }

            temp = temp->next;
        }
    }

    // Cycle check
    if (count != graph->numVertices) {
        printf("\nCycle detected! Topological sort not possible.\n");
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

    topologicalSort(graph);

    return 0;
}