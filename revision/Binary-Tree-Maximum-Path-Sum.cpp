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
    int maxPath = INT_MIN;
public:
    int f(TreeNode* root) {
        if (!root) return 0;

        int lPath = f(root->left);
        int rPath = f(root->right);

        maxPath = max(maxPath, max(root->val, root->val + max(lPath + rPath, max(lPath, rPath))));

        return max(root->val, max(lPath, rPath) + root->val);
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return maxPath;
    }
};