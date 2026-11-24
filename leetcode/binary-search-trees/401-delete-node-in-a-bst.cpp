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
        if (!root)
            return root;
        TreeNode *parent = nullptr, *mover = root;

        while (mover && mover->val != key) {
            parent = mover;
            if (mover->val < key)
                mover = mover->right;
            else
                mover = mover->left;
        }
        if(!mover) return root;

        TreeNode* temp = mover->right;
        while (temp && temp->left)
            temp = temp->left;

        if (temp) {
            temp->left = mover->left;
            temp = mover->right;
        }
        else  temp = mover->left;


        if (parent) {
            if (parent->left == mover)
                parent->left = temp;
            else
                parent->right = temp;
        } else {
            delete mover;
            root = temp;
        }
        return root;
    }
};