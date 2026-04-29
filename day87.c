Problem: Implement Binary Search Iterative - Implement the algorithm.

#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Iterative Binary Search function
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1, mid;
    
    while(low <= high) {
        mid = low + (high - low) / 2;
        
        if(arr[mid] == target) {
            return mid; // Element found
        }
        else if(arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return -1; // Element not found
}

int main() {
    int n, i, target;
    
    // Input size of array
    scanf("%d", &n);
    
    int arr[n];
    
    // Input array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort the array first
    bubbleSort(arr, n);
    
    // Print sorted array
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
