Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

#include <stdio.h>
int main() {
    int n, m;
    // Input number of vertices and edges
    scanf("%d %d", &n, &m);
    int adj[n][n];

    // Initialize matrix with 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // For undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // Print adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}
