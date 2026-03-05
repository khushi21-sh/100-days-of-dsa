#include <stdio.h>

int main()
{
    int stack[100];
    int top = -1;
    int n, m, i;

    scanf("%d", &n);

    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &stack[i]);
        top++;
    }

   
    scanf("%d", &m);

   
    for(i = 0; i < m; i++)
    {
        if(top == -1)
        {
            printf("Stack Underflow");
            return 0;
        }
        top--;
    }

    
    for(i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}