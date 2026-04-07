Problem: Detect cycle in directed graph using DFS and recursion stack.

#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int graph[MAX][MAX];   // Adjacency matrix
bool visited[MAX];
bool recStack[MAX];
int V; // number of vertices

// DFS function to detect cycle
bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;
    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {
            if (!visited[i] && dfs(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }
    recStack[node] = false; // remove from recursion stack
    return false;
}

// Function to check cycle
bool hasCycle() {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    int edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed edge
    }
    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
