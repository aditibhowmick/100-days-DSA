Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

#include <stdio.h>

// Function to find lower bound (first index >= x)
int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n;  // default if not found

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            right = mid - 1; // move left
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

// Function to find upper bound (first index > x)
int upperBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n;  // default if not found

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] > x) {
            ans = mid;
            right = mid - 1; // move left
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n, x;

    // Input
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &x);

    // Function calls
    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    // Output
    printf("%d %d\n", lb, ub);
    return 0;
}
