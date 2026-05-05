#include <stdio.h>
#include <stdlib.h>

// Structure to store value and original index
typedef struct {
    int val;
    int idx;
} Node;

// Merge function
void merge(Node arr[], int left, int mid, int right, int count[]) {
    int n = right - left + 1;
    Node temp[n];

    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;   // smaller element from right
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    // Remaining left elements
    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    // Remaining right elements
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

// Merge Sort
void mergeSort(Node arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);

        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node arr[n];
    int count[n];

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    // Output result
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}