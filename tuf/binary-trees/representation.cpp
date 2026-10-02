#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node (int val) {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void dfs(Node* root) {
    if (!root) return;
    dfs(root->left);
    cout << root->data << " ";
    dfs(root->right);
}

int main () {
    Node* root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->left->right->left = new Node(1);

    dfs(root);
}