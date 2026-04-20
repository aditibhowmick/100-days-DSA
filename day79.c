Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 1000000000

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;
Node* adj[MAX];

// Create node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Heap structure
typedef struct {
    int vertex;
    int dist;
} HeapNode;
HeapNode heap[MAX];
int size = 0;

// Swap
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push
void push(int v, int d) {
    heap[size].vertex = v;
    heap[size].dist = d;
    heapifyUp(size);
    size++;
}

// Pop
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapifyDown(0);
    return root;
}

// Dijkstra
void dijkstra(int n, int source) {
    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[source] = 0;
    push(source, 0);

    while (size > 0) {
        HeapNode temp = pop();
        int u = temp.vertex;

        if (temp.dist > dist[u]) continue;
        Node* curr = adj[u];

        while (curr != NULL) {
            int v = curr->vertex;
            int w = curr->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            curr = curr->next;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}

// Main
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    int source;
    scanf("%d", &source);
    dijkstra(n, source);
    return 0;
}
