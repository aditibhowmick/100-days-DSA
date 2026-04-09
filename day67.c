Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Adjacency list
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int V;

// Function to add edge
void addEdge(int u, int v) {
    adj[u][v] = 1;
}

// DFS function
void dfs(int node) {
    visited[node] = 1;
    for(int i = 0; i < V; i++) {
        if(adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    // Push to stack after visiting all neighbors
    stack[++top] = node;
}

// Topological Sort function
void topologicalSort() {
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
}
// Main function
int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }
    printf("Enter edges (u v):\n");
    for(int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    topologicalSort();
    return 0;
}
