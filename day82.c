#include <stdio.h>

// Function for Lower Bound (first index where arr[i] >= x)
int lower_bound(int arr[], int n, int x) {
    int left = 0, right = n;

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// Function for Upper Bound (first index where arr[i] > x)
int upper_bound(int arr[], int n, int x) {
    int left = 0, right = n;

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int n, x;

    // Input
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);

    // Find bounds
    int lb = lower_bound(arr, n, x);
    int ub = upper_bound(arr, n, x);

    // Output
    printf("%d %d\n", lb, ub);

    return 0;
}