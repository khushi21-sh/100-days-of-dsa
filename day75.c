#include <stdio.h>

#define MAX 1000
#define OFFSET 100000
#define SIZE 200005

int main() {
    int arr[MAX];
    int n = 0;

    while (scanf("%d", &arr[n]) != EOF) {
        n++;
        if (n >= MAX) break;
    }

    int firstIndex[SIZE];

    // initialize properly
    for (int i = 0; i < SIZE; i++)
        firstIndex[i] = -2;

    int prefixSum = 0;
    int maxLen = 0;

    firstIndex[OFFSET] = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int idx = prefixSum + OFFSET;

        // safety check
        if (idx < 0 || idx >= SIZE)
            continue;

        if (firstIndex[idx] != -2) {
            int len = i - firstIndex[idx];
            if (len > maxLen)
                maxLen = len;
        } else {
            firstIndex[idx] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}