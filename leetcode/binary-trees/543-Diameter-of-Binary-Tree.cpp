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
    pair<int, int> depthAndDiameter(TreeNode* root) {
        if (!root) return {0,0};
        auto[lh, ld] = depthAndDiameter(root->left);
        auto[rh, rd]= depthAndDiameter(root->right);

        return {max(lh, rh)+1, max(lh + rh, max(ld, rd))};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return depthAndDiameter(root).second;
    }
};