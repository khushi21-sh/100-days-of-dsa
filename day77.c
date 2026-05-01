#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// adjacency list node
typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];

// create node
Node* create(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->v = v;
    n->next = NULL;
    return n;
}

// add edge (undirected)
void addEdge(int u, int v) {
    Node* n1 = create(v);
    n1->next = adj[u];
    adj[u] = n1;

    Node* n2 = create(u);
    n2->next = adj[v];
    adj[v] = n2;
}

// DFS
void dfs(int u) {
    visited[u] = 1;

    Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->v]) {
            dfs(temp->v);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // start DFS from node 1
    dfs(1);

    // check connectivity
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) count++;
    }

    if (count == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}