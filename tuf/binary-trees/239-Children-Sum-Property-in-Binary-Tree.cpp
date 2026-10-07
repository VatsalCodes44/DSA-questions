#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        // Your code goes here
        if (!root) return true;
        if (!root->left && !root->right) return true;

        if (!checkChildrenSum(root->left)) return false;
        if (!checkChildrenSum(root->right)) return false;
        int sum = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
        return sum == root->val;
    }
};