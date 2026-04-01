#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

unordered_map<int, int> inorderMap;
int postIndex;

Node* build(vector<int>& inorder, vector<int>& postorder, int left, int right) {
    if (left > right) return NULL;

    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);

    int index = inorderMap[rootVal];

    root->right = build(inorder, postorder, index + 1, right);
    root->left = build(inorder, postorder, left, index - 1);

    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> inorder(n), postorder(n);

    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    for (int i = 0; i < n; i++) {
        inorderMap[inorder[i]] = i;
    }

    postIndex = n - 1;

    Node* root = build(inorder, postorder, 0, n - 1);

    preorder(root);

    return 0;
}