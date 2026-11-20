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
    void f(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        if (!root->left && !root->right) ans.push_back(root->val);
        f(root->left, ans);
        f(root->right, ans);
    }
    vector<int> boundary(TreeNode* root) {
        // your code goes here
        vector<int> ans;
        ans.push_back(root->val);
        TreeNode* mover = root->left;
        while (mover && (mover->left || mover->right)) {
            ans.push_back(mover->val);
            if (mover->left)
                mover = mover->left;
            else
                mover = mover->right;
        }

        f(root->left, ans);
        f(root->right, ans);

        int count = 0;
        mover = root->right;
        while (mover && (mover->left || mover->right)) {
            ans.push_back(mover->val);
            if (mover->right)
                mover = mover->right;
            else
                mover = mover->left;
            count++;
        }

        reverse(ans.end() - count, ans.end());

        return ans;
    }
};