#include <stdio.h>

int main() {
    int p, q, i, j;

    scanf("%d", &p);
    int a[p];
    for(i = 0; i < p; i++)
        scanf("%d", &a[i]);

    scanf("%d", &q);
    int b[q];
    for(i = 0; i < q; i++)
        scanf("%d", &b[i]);

    int merged[p + q];
    i = 0;
    j = 0;
    int k = 0;

    while(i < p && j < q) {
        if(a[i] <= b[j])
            merged[k++] = a[i++];
        else
            merged[k++] = b[j++];
    }

    while(i < p)
        merged[k++] = a[i++];

    while(j < q)
        merged[k++] = b[j++];

    for(i = 0; i < p + q; i++)
        printf("%d ", merged[i]);

    return 0;
}