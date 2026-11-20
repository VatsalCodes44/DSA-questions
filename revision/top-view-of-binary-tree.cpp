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

class Solution{
    public:
    vector<int> topView(TreeNode *root){
        //your code goes here
        vector<int> ans;
        if (!root) return ans;
        queue<pair<TreeNode*, int>> q;
        map<int, int> mpp;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto &[top, idx] = q.front();
                q.pop();
                if (mpp.find(idx) == mpp.end()) mpp[idx] = top->val;
                if (top->left) q.push({top->left, idx-1});
                if (top->right) q.push({top->right, idx+1});
            }
        }

        for (auto [idx, val]: mpp) ans.push_back(val);
        return ans;
    }
};