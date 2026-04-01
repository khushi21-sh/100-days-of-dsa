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

void verticalOrder(Node* root) {
    if (!root) return;

    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        Node* node = front.first;
        int hd = front.second;

        mp[hd].push_back(node->val);

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto it : mp) {
        for (int val : it.second) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    Node* root = buildTree(arr);
    verticalOrder(root);

    return 0;
}