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

// Graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

// Queue functions
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int value) {
    q->items[q->rear++] = value;
}

int dequeue(Queue* q) {
    return q->items[q->front++];
}

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

// BFS function
void BFS(Graph* graph, int startVertex) {
    Queue q;
    initQueue(&q);

    graph->visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
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

    int start;
    scanf("%d", &start);

    BFS(graph, start);

    return 0;
}