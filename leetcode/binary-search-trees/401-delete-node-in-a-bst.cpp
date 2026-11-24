#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) {
            if (!root->left) return root->right;
            else if (!root->right) return root->left;
            else {
                TreeNode* mover = root->right;
                while (mover->left) mover = mover->left;
                mover->left = root->left;
                mover = root->right;
                delete root;
                return mover;
            }
        }
        TreeNode* mover = root;
        while (mover->right || mover->left) {
            if (mover->right && mover->right->val == key) break;
            if (mover->left && mover->left->val == key) break;
            else if (mover->val > key) mover = mover->left;
            else mover = mover->right;
        }
        
        if (mover->right && mover->right->val == key) {
            TreeNode* temp = mover->right;
            if (!temp->left) mover->right = temp->right;
            else if (!temp->right) mover->right = temp->left;
            else {
                temp = temp->right;
                while (temp->left) temp = temp->left;
                temp->left = mover->right->left;
                TreeNode* temp2 = mover->right;
                mover->right = mover->right->right;
                delete temp2;
            }
        }
        else if (mover->left && mover->left->val == key) {
            TreeNode* temp = mover->left;
            if (!temp->left) mover->left = temp->right;
            else if (!temp->right) mover->left = temp->left;
            else {
                temp = temp->right;
                while (temp->left) temp = temp->left;
                temp->left = mover->left->left;
                TreeNode* temp2 = mover->left;
                mover->left = mover->left->right;
                delete temp2;
            }
        }
        return root;
    }
};