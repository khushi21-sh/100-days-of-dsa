#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];

// find minimum key vertex not in MST
int minKey(int key[], int visited[]) {
    int min = INT_MAX, minIndex = -1;

    for (int v = 1; v <= n; v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Prim's algorithm
int primMST() {
    int parent[MAX];
    int key[MAX];
    int visited[MAX];

    // initialize
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    // start from node 1
    key[1] = 0;

    for (int count = 1; count <= n - 1; count++) {

        int u = minKey(key, visited);
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // compute MST weight
    int totalWeight = 0;
    for (int i = 2; i <= n; i++) {
        totalWeight += graph[i][parent[i]];
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    // input edges (undirected)
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        // keep minimum weight if multiple edges exist
        if (graph[u][v] == 0 || w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    printf("%d\n", primMST());

    return 0;
}