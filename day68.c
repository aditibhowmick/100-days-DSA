#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int V;
// Function to add edge
void addEdge(int u, int v) {
    adj[u][v] = 1;
    indegree[v]++;
}

// Kahn's Algorithm
void topologicalSort() {
    int queue[MAX], front = 0, rear = 0;
    // Step 1: Push nodes with indegree 0
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    printf("Topological Order: ");

    // Step 2: Process queue
    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        // Reduce indegree of neighbors
        for(int i = 0; i < V; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Step 3: Check for cycle
    if(count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}
// Main function
int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    // Initialize
    for(int i = 0; i < V; i++) {
        indegree[i] = 0;
        for(int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
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
