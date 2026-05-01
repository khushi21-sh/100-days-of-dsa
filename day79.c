#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// adjacency list node
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

// graph
Node* adj[MAX];

// heap node
typedef struct {
    int v;
    int dist;
} HeapNode;

// min heap
typedef struct {
    HeapNode arr[MAX];
    int size;
} MinHeap;

// create node
Node* createNode(int v, int w) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->v = v;
    n->w = w;
    n->next = NULL;
    return n;
}

// add edge (undirected or directed depending on use)
void addEdge(int u, int v, int w) {
    Node* n = createNode(v, w);
    n->next = adj[u];
    adj[u] = n;
}

// heap swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

// heapify up
void heapifyUp(MinHeap* h, int i) {
    while (i > 0 && h->arr[(i - 1) / 2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// heapify down
void heapifyDown(MinHeap* h, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;
    if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

// push
void push(MinHeap* h, int v, int dist) {
    h->arr[h->size].v = v;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// pop min
HeapNode pop(MinHeap* h) {
    HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

int empty(MinHeap* h) {
    return h->size == 0;
}

// Dijkstra
void dijkstra(int n, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    MinHeap pq;
    pq.size = 0;

    dist[src] = 0;
    push(&pq, src, 0);

    while (!empty(&pq)) {
        HeapNode cur = pop(&pq);
        int u = cur.v;

        if (visited[u]) continue;
        visited[u] = 1;

        Node* temp = adj[u];

        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&pq, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // print distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        // undirected graph (remove if directed)
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}