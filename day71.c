#include <stdio.h>

#define EMPTY -1
#define MAX 100

int table[MAX];
int m;

// Initialize hash table
void init() {
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;
}

// Insert using quadratic probing
void insert(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
}

// Search using quadratic probing
int search(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == key)
            return 1;

        if (table[idx] == EMPTY)
            return 0; // stop early (key not present)
    }

    return 0;
}

// Driver
int main() {
    int n;
    scanf("%d", &m);
    scanf("%d", &n);

    init();

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(key);
        } else if (op[0] == 'S') {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}