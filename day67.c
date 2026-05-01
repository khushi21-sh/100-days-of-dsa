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

// Stack
typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int val) {
    s->items[++s->top] = val;
}

int pop(Stack* s) {
    return s->items[s->top--];
}

int isEmpty(Stack* s) {
    return s->top == -1;
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

// Add edge (directed)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// DFS for topo sort
void topoDFS(Graph* graph, int v, Stack* s) {
    graph->visited[v] = 1;

    Node* temp = graph->adjLists[v];

    while (temp) {
        int adj = temp->vertex;
        if (!graph->visited[adj]) {
            topoDFS(graph, adj, s);
        }
        temp = temp->next;
    }

    // Push after visiting all neighbors
    push(s, v);
}

// Topological sort
void topologicalSort(Graph* graph) {
    Stack s;
    initStack(&s);

    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            topoDFS(graph, i, &s);
        }
    }

    // Print stack
    while (!isEmpty(&s)) {
        printf("%d ", pop(&s));
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