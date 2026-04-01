#include <iostream>
#include <unordered_map>
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

Node* buildTree(int preorder[], int inorder[], int &preIndex, 
                int inStart, int inEnd, unordered_map<int, int> &mp) {
    
    if (inStart > inEnd) return NULL;

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    int inIndex = mp[rootVal];

    root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1, mp);
    root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd, mp);

    return root;
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cin >> n;

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[inorder[i]] = i;
    }

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, preIndex, 0, n - 1, mp);

    postorder(root);

    return 0;
}