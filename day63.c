Problem: Perform DFS starting from a given source vertex using recursion.

#include <stdio.h>
#define MAX 100
int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // visited array
int n;               // number of vertices

// DFS function
void dfs(int v) {
    printf("%d ", v);     // print current vertex
    visited[v] = 1;       // mark as visited
    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);       // recursive call
        }
    }
}

int main() {
    int s;
    // input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    // initialize visited array
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    // input starting vertex
    printf("Enter starting vertex: ");
    scanf("%d", &s);
    // DFS traversal
    printf("DFS Traversal: ");
    dfs(s);
    return 0;
}
