#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
typedef struct Node {
    float data;
    struct Node* next;
} Node;

// Insert in sorted order (Insertion Sort inside bucket)
void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL && curr->next->data < value) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Create buckets
    Node* buckets[n];
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];   // bucket index
        insertSorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->data;
            curr = curr->next;
        }
    }

    // Output sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}