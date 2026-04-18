Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

#include <stdio.h>
#define MAX 1000
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = 0, maxLen = 0;

    // Store prefix sums and their first index
    int prefixSum[MAX];
    int index[MAX];
    int size = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum becomes 0
        if (sum == 0) {
            maxLen = i + 1;
        }

        // Check if sum already exists
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (prefixSum[j] == sum) {
                int length = i - index[j];
                if (length > maxLen)
                    maxLen = length;
                found = 1;
                break;
            }
        }

        // If not found, store it
        if (!found) {
            prefixSum[size] = sum;
            index[size] = i;
            size++;
        }
    }
    printf("%d\n", maxLen);
    return 0;
}
