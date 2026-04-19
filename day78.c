Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

#include <stdio.h>
#include <stdbool.h>
#define MAX 100
#define INF 1000000
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int graph[MAX][MAX];

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    bool visited[MAX] = {false};
    int key[MAX];

    // Initialize keys with large value
    for (int i = 1; i <= n; i++) {
        key[i] = INF;
    }

    key[1] = 0;  // Start from node 1
    int totalWeight = 0;
    for (int count = 1; count <= n; count++) {
        int u = -1;

        // Find minimum key vertex
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }
        visited[u] = true;
        totalWeight += key[u];

        // Update adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }
    printf("%d\n", totalWeight);
    return 0;
}
