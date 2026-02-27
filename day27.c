#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1;   
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m;

    scanf("%d", &n);

    struct Node *head1 = NULL, *tail1 = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL, *tail2 = NULL;

    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    

    for (struct Node* temp1 = head1; temp1 != NULL; temp1 = temp1->next) {
        for (struct Node* temp2 = head2; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->data == temp2->data) {
                tail2->next = temp1;
                break;
            }
        }
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}