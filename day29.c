#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k, i;
    scanf("%d", &n);

    if(n == 0)
        return 0;

    struct Node *head = NULL, *last = NULL, *newNode;

    
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    scanf("%d", &k);

    k = k % n;   

    if(k == 0) {
        struct Node* temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    last->next = head;

    
    struct Node* temp = head;
    for(i = 1; i < n - k; i++) {
        temp = temp->next;
    }

    
    head = temp->next;
    temp->next = NULL;

   
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}