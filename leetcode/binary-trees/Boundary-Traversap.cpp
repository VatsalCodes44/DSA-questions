#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution {
  public:

    void inorder(Node* root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        inorder(root->right, ans);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> leftBottomBoundary;
        vector<int> rightBoundary;

        leftBottomBoundary.push_back(root->data);

        Node* mover = root->left;
        while (mover && (mover->left || mover->right)) {
            leftBottomBoundary.push_back(mover->data);
            if (mover->left) mover = mover->left;
            else mover = mover->right;
        }

        inorder(root->left, leftBottomBoundary);
        inorder(root->right, leftBottomBoundary);

        mover = root->right;
        while (mover && (mover->left || mover->right)) {
            rightBoundary.push_back(mover->data);
            if (mover->right) mover = mover->right;
            else mover = mover->left;
        }

        while (rightBoundary.size()) {
            leftBottomBoundary.push_back(rightBoundary.back());
            rightBoundary.pop_back();
        }
        return leftBottomBoundary;
    }
};