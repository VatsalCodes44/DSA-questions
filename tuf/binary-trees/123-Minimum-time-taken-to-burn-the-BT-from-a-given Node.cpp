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

class Solution {
   public:
    int timeToBurnTree(TreeNode* root, int start) {
        // your code goes here
        if (!root) return 0;
        map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* target = nullptr;

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->data == start) target = curr;

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
        if (!target) return 0;
        q.push(target);
        visited[target] = true;

        int maxTime = 0;
        while (!q.empty()) {
            int n = q.size();
            maxTime++;

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                visited[curr] = true;

                if (parent.find(curr) != parent.end() &&
                    visited.find(parent[curr]) == visited.end()) {
                    visited[parent[curr]] == true;
                    q.push(parent[curr]);
                }

                if (curr->left && visited.find(curr->left) == visited.end()) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
            }
        }

        return maxTime - 1;
    }
};
