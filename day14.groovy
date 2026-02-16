#include <stdio.h>

int main() {
    int n, i, j;
    int a[10][10];   
    int flag = 1;

    scanf("%d", &n);


    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j && a[i][j] != 1) {
                flag = 0;
            }
            if(i != j && a[i][j] != 0) {
                flag = 0;
            }
        }
    }

    if(flag == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
