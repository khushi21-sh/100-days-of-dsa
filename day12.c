#include <stdio.h>

int main() {
    int m, n, i, j;

    scanf("%d %d", &m, &n);

    int A[m][n];

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // must be square matrix
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int symmetric = 1;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if (A[i][j] != A[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric)
            break;
    }

    if (symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}