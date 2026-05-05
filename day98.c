#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start;
    int end;
} Interval;

// Sort by start time
int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), cmp);

    // Step 2: Merge intervals
    Interval res[n];
    int idx = 0;

    res[0] = arr[0];

    for (int i = 1; i < n; i++) {
        // Overlapping case
        if (arr[i].start <= res[idx].end) {
            if (arr[i].end > res[idx].end)
                res[idx].end = arr[i].end;
        } else {
            // Non-overlapping → new interval
            idx++;
            res[idx] = arr[i];
        }
    }

    // Output merged intervals
    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", res[i].start, res[i].end);
    }

    return 0;
