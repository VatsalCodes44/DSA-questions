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
    vector<int> findMinMax(TreeNode* root) {
        // Your code goes here
        vector<int> ans;
        TreeNode* mover = root;
        while (mover->left) mover = mover->left;
        ans.push_back(mover->val);
        mover = root;
        while (mover->right) mover = mover->right;
        ans.push_back(mover->val);
        return ans;
    }
};