#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;


void push(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    int val;
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);

    return val;
}


int evaluatePostfix(char exp[])
{
    int i = 0, a, b;

    while(exp[i] != '\0')
    {
        
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }

        
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
        {
            b = pop();
            a = pop();

            switch(exp[i])
            {
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b); break;
            }
        }

        i++;
    }

    return pop();
}

int main()
{
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("Result = %d", result);

    return 0;
}