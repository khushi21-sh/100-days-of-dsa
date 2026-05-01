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
    int V;
    Node** adj;
    int* visited;
} Graph;

// Create node
Node* createNode(int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

// Create graph
Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;

    g->adj = (Node**)malloc((V + 1) * sizeof(Node*));
    g->visited = (int*)malloc((V + 1) * sizeof(int));

    for (int i = 0; i <= V; i++) {
        g->adj[i] = NULL;
        g->visited[i] = 0;
    }

    return g;
}

// Add edge (undirected)
void addEdge(Graph* g, int u, int v) {
    Node* n1 = createNode(v);
    n1->next = g->adj[u];
    g->adj[u] = n1;

    Node* n2 = createNode(u);
    n2->next = g->adj[v];
    g->adj[v] = n2;
}

// DFS
void dfs(Graph* g, int v) {
    g->visited[v] = 1;

    Node* temp = g->adj[v];
    while (temp) {
        if (!g->visited[temp->vertex]) {
            dfs(g, temp->vertex);
        }
        temp = temp->next;
    }
}

// Count connected components
int countComponents(Graph* g, int n) {
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!g->visited[i]) {
            dfs(g, i);
            count++;
        }
    }

    return count;
}

// Driver
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* g = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    printf("%d\n", countComponents(g, n));

    return 0;
}