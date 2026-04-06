Problem: Perform DFS starting from a given source vertex using recursion.

#include <stdio.h>
#define MAX 100
int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];    // Visited array
int n;               // Number of vertices

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    // Initialize visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("Enter starting vertex: ");
    scanf("%d", &s);
    printf("DFS Traversal: ");
    dfs(s);
    return 0;
}
