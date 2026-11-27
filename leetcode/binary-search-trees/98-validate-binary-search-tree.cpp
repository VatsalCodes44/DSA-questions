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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode* root, int start, int end) {
        if (!root) return true;
        if (start > root->val || root->val > end)return false;
        if ((root->val == INT_MIN && root->left) || ( root->val == INT_MAX && root->right))return false;
        bool left = root->left ? f(root->left, start, root->val-1) : true;
        if (!left)return false;
        bool right = root->right ? f(root->right, root->val+1, end) : true;
        if (!right) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return f(root, INT_MIN, INT_MAX);
    }
};