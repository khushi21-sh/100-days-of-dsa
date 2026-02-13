#include <stdio.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int i = 0, len = 0;

    // find length manually
    while (s[len] != '\0')
        len++;

    int left = 0, right = len - 1;
    char temp;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    printf("%s", s);
    return 0;
}