#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Node for adjacency list (weighted)
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Min Heap (Priority Queue)
typedef struct MinHeapNode {
    int v;
    int dist;
} MinHeapNode;

typedef struct MinHeap {
    int size;
    int capacity;
    int pos[MAX];
    MinHeapNode** array;
} MinHeap;

// Graph
typedef struct Graph {
    int V;
    Node** adjLists;
} Graph;

// Create node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Create graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    graph->adjLists = (Node**)malloc(V * sizeof(Node*));

    for (int i = 0; i < V; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

/* ---------- Min Heap Helpers ---------- */

MinHeapNode* newHeapNode(int v, int dist) {
    MinHeapNode* node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return heap;
}

void swapNodes(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size &&
        heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;

    if (right < heap->size &&
        heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

MinHeapNode* extractMin(MinHeap* heap) {
    if (isEmpty(heap)) return NULL;

    MinHeapNode* root = heap->array[0];

    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(MinHeap* heap, int v, int dist) {
    int i;
    for (i = 0; i < heap->size; i++) {
        if (heap->array[i]->v == v) {
            heap->array[i]->dist = dist;
            break;
        }
    }

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        swapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isInHeap(MinHeap* heap, int v) {
    for (int i = 0; i < heap->size; i++)
        if (heap->array[i]->v == v)
            return 1;
    return 0;
}

/* ---------- Dijkstra ---------- */

void dijkstra(Graph* graph, int src) {
    int V = graph->V;

    int dist[MAX];

    MinHeap* heap = createMinHeap(V);

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        heap->array[i] = newHeapNode(i, dist[i]);
    }

    heap->array[src] = newHeapNode(src, 0);
    dist[src] = 0;

    heap->size = V;

    while (!isEmpty(heap)) {
        MinHeapNode* minNode = extractMin(heap);
        int u = minNode->v;

        Node* temp = graph->adjLists[u];

        while (temp) {
            int v = temp->vertex;

            if (isInHeap(heap, v) &&
                dist[u] != INT_MAX &&
                dist[u] + temp->weight < dist[v]) {

                dist[v] = dist[u] + temp->weight;
                decreaseKey(heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print distances
    for (int i = 0; i < V; i++) {
        printf("%d ", dist[i]);
    }
}

// Driver
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}