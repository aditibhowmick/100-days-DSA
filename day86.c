Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose 
square is less than or equal to the given number.

#include <stdio.h>
int integerSquareRoot(int n) {
    if (n == 0 || n == 1)
        return n;

    int left = 0, right = n, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Use long long to prevent overflow
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;
        } 
        else if (square < n) {
            ans = mid;      // Store possible answer
            left = mid + 1; // Search right half
        } 
        else {
            right = mid - 1; // Search left half
        }
    }

    return ans;
}
int main() {
    int n;

    // Input number
    scanf("%d", &n);

    // Output integer square root
    printf("%d", integerSquareRoot(n));
    return 0;
}
