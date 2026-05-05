#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place k cows with at least 'dist' spacing
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;              // place first cow at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];

            if (count == k)
                return 1;       // possible
        }
    }
    return 0;                   // not possible
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Step 1: Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    // Step 2: Binary Search on answer (distance)
    int left = 1;
    int right = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;          // possible → try bigger distance
            left = mid + 1;
        } else {
            right = mid - 1;    // not possible → reduce distance
        }
    }

    printf("%d", ans);

    return 0;
}