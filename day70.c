#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 1000000000

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];

int dist[MAX];

int n, m;

// Bellman-Ford
int bellmanFord(int src) {

    // Step 1: Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    // Step 2: Relax edges (n - 1) times
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return 1; // Negative cycle detected
        }
    }

    return 0;
}

// Driver
int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    if (bellmanFord(src)) {
        printf("NEGATIVE CYCLE\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i]);
        }
    }

    return 0;
