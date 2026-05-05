#include <stdio.h>

int main() {
    int n, x;

    // Input size
    scanf("%d", &n);
    int arr[n];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    scanf("%d", &x);

    // -------- Sorting (Simple Bubble Sort) --------
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // -------- Binary Search Iterative --------
    int left = 0, right = n - 1, found = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x) {
            found = mid;
            break;
        }
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // -------- Output --------
    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // Print search result
    if (found != -1)
        printf("Element found at index %d", found);
    else
        printf("Element not found");

    return 0;
}