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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Recursive {
public:
    void bfs(queue<TreeNode*>& q, vector<vector<int>>& ansArr) {
        if (q.empty()) return;
        int n = q.size();
        vector<int> ans;
        ans.reserve(q.size());
        for (int i = 0; i < n; i++) {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        ansArr.push_back(ans);
        bfs(q, ansArr);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ansArr;
        if (!root) return ansArr;
        bfs(q, ansArr);
        return ansArr;
    }
};

class Iterative {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ansArr;
        if (!root) return ansArr;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                ans.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            ansArr.push_back(ans);
        }
        return ansArr;
    }
};