#include <stdio.h>
#include <string.h>

#define MAX 100000

int main() {
    char s[MAX];
    scanf("%s", s);

    int visited[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if (visited[idx]) {
            printf("%c\n", s[i]);
            return 0;
        }

        visited[idx] = 1;
    }

    printf("-1\n");
    return 0;
}