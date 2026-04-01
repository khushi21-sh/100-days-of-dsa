#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

Node* findLCA(Node* root, int p, int q) {
    while (root != NULL) {
        if (p < root->data && q < root->data) {
            root = root->left;
        }
        else if (p > root->data && q > root->data) {
            root = root->right;
        }
        else {
            return root; 
        }
    }
    return NULL;
}

int main() {
    int N;
    cin >> N;

    Node* root = NULL;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int p, q;
    cin >> p >> q;

    Node* lca = findLCA(root, p, q);

    if (lca)
        cout << lca->data;

    return 0;
}