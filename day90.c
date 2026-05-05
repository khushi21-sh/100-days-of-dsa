#include <stdio.h>

// Check if painters can paint within maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        // If a single board > maxTime → impossible
        if (arr[i] > maxTime)
            return 0;

        if (currTime + arr[i] <= maxTime) {
            currTime += arr[i];
        } else {
            painters++;
            currTime = arr[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Binary Search range
    int left = 0, right = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > left)
            left = arr[i];   // max board length
        right += arr[i];     // total length
    }

    // Binary Search
    while (left <= right) {
        int mid = (left + right) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;          // possible → try smaller time
            right = mid - 1;
        } else {
            left = mid + 1;     // not possible → increase time
        }
    }

    printf("%d", ans);

    return 0;
}