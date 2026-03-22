#include <stdio.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;


int empty() {
    return (front == -1);
}


int full() {
    return (rear == MAX - 1);
}


void push_front(int x) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }

    dq[front] = x;
}


void push_back(int x) {
    if (full()) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    dq[rear] = x;
}


void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}


void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}


void get_front() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", dq[front]);
}


void get_back() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", dq[rear]);
}


void size() {
    if (empty())
        printf("0\n");
    else
        printf("%d\n", rear - front + 1);
}


void display() {
    if (empty()) return;

    for (int i = front; i <= rear; i++) {
        printf("%d ", dq[i]);
    }
    printf("\n");
}


void reverse() {
    int i = front, j = rear;
    while (i < j) {
        int temp = dq[i];
        dq[i] = dq[j];
        dq[j] = temp;
        i++; j--;
    }
}


void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (dq[i] > dq[j]) {
                int temp = dq[i];
                dq[i] = dq[j];
                dq[j] = temp;
            }
        }
    }
}


void clear() {
    front = rear = -1;
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') { 
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0] == 'p' && op[5] == 'b') { 
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0] == 'p' && op[4] == 'f') { 
            pop_front();
        }
        else if (op[0] == 'p' && op[4] == 'b') {
            pop_back();
        }
        else if (op[0] == 'f') { 
            get_front();
        }
        else if (op[0] == 'b') { 
            get_back();
        }
        else if (op[0] == 's') { 
            if (op[1] == 'i')
                size();
            else
                sort();
        }
        else if (op[0] == 'e') { 
            if (empty())
                printf("1\n");
            else
                printf("0\n");
        }
        else if (op[0] == 'c') { 
            clear();
        }
        else if (op[0] == 'r') { 
            reverse();
        }
    }

    display();
    return 0;
}