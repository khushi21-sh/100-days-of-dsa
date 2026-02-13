#include <stdio.h>

int main() {
    int m, n, i, j;

    scanf("%d %d", &m, &n);

    int A[m][n], B[m][n], C[m][n];

    // read first matrix
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // read second matrix
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // add matrices
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // print result
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}