#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution{
    public:
    //                                            col,      row, val
    void f (TreeNode* root, int col, int row, map<int, pair<int, int>>& mpp) {
        if (!root) return;
        if (mpp.find(col) == mpp.end()) mpp[col] = {row, root->data};
        else {
            auto [r, v] = mpp[col];
            if (row < r) mpp[col] = {row, root->data};
        }
        f(root->left, col-1, row+1, mpp);
        f(root->right, col+1, row+1, mpp);
    }
    vector<int> topView(TreeNode *root){
        //your code goes here
        //  col, val
        map<int, pair<int, int>> mpp;

        f(root, 0, 0, mpp);

        vector<int> ans;

        for (auto i: mpp){
            ans.push_back(i.second.second);
        }

        return ans;
    }
};