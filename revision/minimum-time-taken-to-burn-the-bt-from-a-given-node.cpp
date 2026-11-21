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
    TreeNode* f(TreeNode* root, int start) {
        if (!root) return nullptr;
        if (root->val == start) return root;
        TreeNode* left = f(root->left, start);
        if (left && left->val == start) return left;
        TreeNode* right = f(root->right, start);
        if (right && right->val == start) return right;
        return nullptr;
    }
    int timeToBurnTree(TreeNode* root, int start) {
        if (!root) return 0;
        TreeNode* startNode = f(root, start);

        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) {
                    parent[curr->left] = curr;
                    q.push(curr->left);
                }
                if (curr->right) {
                    parent[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        map<TreeNode*, bool> visited;
        q.push(startNode);
        int time = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (parent.find(curr) != parent.end() &&
                    visited[parent[curr]] == false)
                    q.push(parent[curr]);
                if (curr->left && !visited[curr->left]) q.push(curr->left);
                if (curr->right && !visited[curr->right]) q.push(curr->right);
                visited[curr] = true;
            }
            time++;
        }
        return time-1;
    }
};