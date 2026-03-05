#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

int priority(char x)
{
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i=0, j=0;

    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        if(isalnum(infix[i]))  
        {
            postfix[j++] = infix[i];
        }
        else                   
        {
            while(top!=-1 && priority(stack[top]) >= priority(infix[i]))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        i++;
    }

    while(top != -1)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}