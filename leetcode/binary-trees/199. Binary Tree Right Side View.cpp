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
    void f(TreeNode* root, int row, vector<int>& ans) {
        if (!root) return;
        if (row == ans.size()) ans.push_back(root->val);  // first node seen at this depth
        f(root->right, row + 1, ans);   // right first
        f(root->left, row + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        f(root, 0, ans);
        return ans;
    }
};