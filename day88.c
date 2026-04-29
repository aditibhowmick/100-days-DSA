Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is 
maximized.

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to check if cows can be placed with minimum distance = dist
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int count = 1; // First cow placed at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];

            if (count == k) {
                return 1; // Successfully placed all cows
            }
        }
    }
    return 0; // Cannot place all cows
}

int main() {
    int n, k;

    // Input number of stalls and cows
    scanf("%d %d", &n, &k);

    int stalls[n];

    // Input stall positions
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;

    // Binary Search on answer
    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            result = mid;   // Possible answer
            low = mid + 1;  // Try for larger distance
        } else {
            high = mid - 1; // Try smaller distance
        }
    }

    // Output maximum minimum distance
    printf("%d\n", result);
    return 0;
}
