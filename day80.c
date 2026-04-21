Problem: Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may 
contain positive or negative edge weights, but it does not contain any negative weight cycles.

#include <stdio.h>
#define INF 1000000000   // A large value to represent infinity

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int dist[n][n];
    printf("Enter adjacency matrix:\n");

    // Input and preprocessing (-1 → INF)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            if (dist[i][j] == -1 && i != j) {
                dist[i][j] = INF;
            }
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // Update shortest path if possible
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Output result (convert INF back to -1)
    printf("\nShortest distance matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
