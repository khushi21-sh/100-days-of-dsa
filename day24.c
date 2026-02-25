#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, key, value;
    struct Node *head = NULL, *newNode, *temp, *prev;


    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    
    scanf("%d", &key);

    temp = head;
    prev = NULL;

    
    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
    } else {
    
        while(temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

    
        if(temp != NULL) {
            prev->next = temp->next;
            free(temp);
        }
    }


    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}