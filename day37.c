#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    int i;
    
    
    for (i = size - 1; i >= 0 && pq[i] > x; i--) {
        pq[i + 1] = pq[i];
    }
    
    pq[i + 1] = x;
    size++;
}


void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    
    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }
    size--;
}


void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[0]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') { 
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') { 
            delete();
        } else if (op[0] == 'p') { 
            peek();
        }
    }

    return 0;
}