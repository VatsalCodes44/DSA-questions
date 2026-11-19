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
    int maxD = 0;
public:
    int f(TreeNode* root) {
        if (!root) return 0;
        int left = f(root->left);
        int right = f(root->right);
        this->maxD = max(this->maxD, left+right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return maxD;
    }
};