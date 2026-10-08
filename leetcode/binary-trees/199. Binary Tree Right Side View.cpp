#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int vsl;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : vsl(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : vsl(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : vsl(x), left(left), right(right) {}
};

class Solution {
 public: 
    //                                            row       col  val
    void f (TreeNode* root, int row, map<int, pair<int, int>>& mpp) {
        if (!root) return;
        mpp[row] = {col, root->val};
            
        f(root->left, row+1, col-1, mpp);
        f(root->right, row+1, col+1, mpp);

    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, pair<int, int>> mpp;

        f(root, 0, 0, mpp);

        vector<int> ans;
        for (auto &[key, value]: mpp) ans.push_back(value.second);

        return ans;
    }
};