#include <stdio.h>

int main() {
    int n, i;

    scanf("%d", &n);
    int arr[n];

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // first element is always unique
    printf("%d ", arr[0]);

    for(i = 1; i < n; i++) {
        if(arr[i] != arr[i-1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}