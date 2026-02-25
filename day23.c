#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* create(int n) {
    struct Node *head = NULL, *newNode, *temp;
    int i, value;

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

int main() {
    int n, m;
    struct Node *list1, *list2;
    struct Node *merged = NULL, *temp = NULL;

    scanf("%d", &n);
    list1 = create(n);

    scanf("%d", &m);
    list2 = create(m);


    while(list1 != NULL && list2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        if(list1->data < list2->data) {
            newNode->data = list1->data;
            list1 = list1->next;
        } else {
            newNode->data = list2->data;
            list2 = list2->next;
        }

        newNode->next = NULL;

        if(merged == NULL) {
            merged = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }


    while(list1 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = list1->data;
        newNode->next = NULL;

        if(merged == NULL) {
            merged = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        list1 = list1->next;
    }

    while(list2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = list2->data;
        newNode->next = NULL;

        if(merged == NULL) {
            merged = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        list2 = list2->next;
    }
    
    while(merged != NULL) {
        printf("%d ", merged->data);
        merged = merged->next;
    }

    return 0;
}