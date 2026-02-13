#include <stdio.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int len = 0;
    while (s[len] != '\0')
        len++;

    int left = 0, right = len - 1;
    int isPal = 1;

    while (left < right) {
        if (s[left] != s[right]) {
            isPal = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPal)
        printf("YES");
    else
        printf("NO");

    return 0;
}