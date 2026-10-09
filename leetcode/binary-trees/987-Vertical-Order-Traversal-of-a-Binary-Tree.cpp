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
    void dfs(TreeNode* root, int r, int c, vector<tuple<int,int,int>>& nodes) {
        if (!root) return;
        nodes.push_back(make_tuple(c, r, root->val));
        dfs(root->left, r + 1, c - 1, nodes);
        dfs(root->right, r + 1, c + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;   // (col, row, val)
        dfs(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end());   // by col, then row, then val

        vector<vector<int>> ans;
        int prevCol = INT_MIN;
        for (int i = 0; i < nodes.size(); i++) {
            auto [c,r,v] = nodes[i];
            if (c != prevCol) {
                ans.push_back({});
                prevCol = c;
            }
            ans.back().push_back(v);
        }
        return ans;
    }
};

class BFS {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ansArr;
        if (!root)
            return ansArr;
        queue<tuple<TreeNode*, int, int>> level;
        level.push(make_tuple(root, 0, 0));

        map<int, map<int, multiset<int>>> verticle;

        while (!level.empty()) {
            int n = level.size();
            for (int i = 0; i < n; i++) {
                auto [curr, row, hd] = level.front();
                level.pop();
                verticle[hd][row].insert(curr->val);
                if (curr->left) level.push(make_tuple(curr->left, row + 1, hd - 1));
                if (curr->right) level.push(make_tuple(curr->right, row + 1, hd + 1));
            }
        }

        for (auto &[key, rows]: verticle) {
            vector<int> ans;
            for (auto &[row, vals]: rows) {
                for (auto &x: vals) ans.push_back(x);
            }
            ansArr.push_back(ans);
        }

        return ansArr;
    }
};