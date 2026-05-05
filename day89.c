#include <stdio.h>

// Check if allocation is possible with maxPages limit
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages → impossible
        if (arr[i] > maxPages)
            return 0;

        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students++;
            pagesSum = arr[i];

            if (students > m)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case
    if (m > n) {
        printf("-1");
        return 0;
    }

    // Binary Search on answer
    int left = 0, right = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > left)
            left = arr[i];   // max element
        right += arr[i];     // sum of all pages
    }

    while (left <= right) {
        int mid = (left + right) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;          // possible → try smaller
            right = mid - 1;
        } else {
            left = mid + 1;     // not possible → increase
        }
    }

    printf("%d", ans);

    return 0;
}