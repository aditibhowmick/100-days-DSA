Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 5   // Number of vertices

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Structure for priority queue node
struct PQNode {
    int vertex;
    int distance;
};

// Create new adjacency node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Function to find vertex with minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra Algorithm
void dijkstra(struct Node* adj[], int src) {
    int dist[V];
    int visited[V];

    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
          int weight = temp->weight;

            if (!visited[v] && dist[u] != INT_MAX &&
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Main function
int main() {
    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // Example graph
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 4, 1, 3);
    addEdge(adj, 4, 2, 9);
    addEdge(adj, 4, 3, 2);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 3, 2, 6);

    dijkstra(adj, 0);
    return 0;
}
