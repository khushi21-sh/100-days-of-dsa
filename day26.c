#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    int n;

    
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = createNode(value);

        
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}