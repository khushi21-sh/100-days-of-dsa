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

Node* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

Node* findLCA(Node* root, int p, int q) {
    if (root == NULL) return NULL;

    if (root->data == p || root->data == q) {
        return root;
    }

    Node* left = findLCA(root->left, p, q);
    Node* right = findLCA(root->right, p, q);

    if (left != NULL && right != NULL) {
        return root; 
    }

    return (left != NULL) ? left : right;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    Node* root = buildTree(arr);

    int p, q;
    cin >> p >> q;

    Node* lca = findLCA(root, p, q);

    if (lca)
        cout << lca->data;

    return 0;
}