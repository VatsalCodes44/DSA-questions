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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<pair<TreeNode*, int>> q;
        map<int, map<int, multiset<int>>> mpp;
        q.push({root, 0});
        int lvl = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [node, idx] = q.front();
                q.pop();
                mpp[idx][lvl].insert(node->val);
                if (node->left)
                    q.push({node->left, idx - 1});
                if (node->right)
                    q.push({node->right, idx + 1});
            }
            lvl++;
        }

        for (auto& [idx, verticle] : mpp) {
            vector<int> arr;
            for (auto& [lvl, mSets] : verticle) {
                for (auto i : mSets)
                    arr.push_back(i);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};