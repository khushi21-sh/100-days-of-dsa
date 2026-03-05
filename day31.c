#include <stdio.h>

int stack[100], top = -1;

int main() {
    int n, op, val, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &op);

        if(op == 1) {          
            scanf("%d", &val);
            top++;
            stack[top] = val;
        }

        else if(op == 2) {     
            if(top == -1)
                printf("Stack Underflow\n");
            else {
                printf("%d\n", stack[top]);
                top--;
            }
        }

        else if(op == 3) {     
            for(int j = top; j >= 0; j--)
                printf("%d ", stack[j]);
            printf("\n");
        }
    }

    return 0;
}