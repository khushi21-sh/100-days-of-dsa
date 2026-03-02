#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

int main() {
    int n, i;
    scanf("%d", &n);

    struct Node *head = NULL, *last = NULL, *newNode;

    
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d", &newNode->coeff, &newNode->exp);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

   
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d", temp->coeff);

        if(temp->exp > 1)
            printf("x^%d", temp->exp);
        else if(temp->exp == 1)
            printf("x");

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}