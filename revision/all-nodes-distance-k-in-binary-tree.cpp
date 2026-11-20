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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (k == 0) {
            ans.push_back(target->val);
            return ans;
        }
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> mpp;

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) {
                    mpp[curr->left] = curr;
                    q.push(curr->left);
                }
                if (curr->right) {
                    mpp[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (mpp.find(curr) != mpp.end() &&
                    visited.find(mpp[curr]) == visited.end()) {
                    q.push(mpp[curr]);
                }
                if (curr->left && visited.find(curr->left) == visited.end()) {
                    q.push(curr->left);
                }
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    q.push(curr->right);
                }
                visited[curr] = true;
            }
            k--;
            if (k == 0)
                break;
        }
        if (k == 0) {
            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();
                ans.push_back(curr->val);
            }
        }
        return ans;
    }
};