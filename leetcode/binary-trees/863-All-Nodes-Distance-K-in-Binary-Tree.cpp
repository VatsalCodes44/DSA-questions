#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void makeParents(TreeNode* root, map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) {
                    q.push(curr->left);
                    parent[curr->left] = curr;
                }
                if (curr->right) {
                    q.push(curr->right);
                    parent[curr->right] = curr;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (!root) return ans;
        if (k == 0) {
            ans.push_back(target->val);
            return ans;
        }
        map<TreeNode*, TreeNode*> parent;
        makeParents(root, parent);

        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        while (!q.empty()) {
            k--;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (parent.find(curr) != parent.end() && visited.find(parent[curr]) == visited.end()) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }

                if (curr->left && visited.find(curr->left) == visited.end()) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if (curr->right && visited.find(curr->right) == visited.end()) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
            }
            if (k == 0) break;
        }

        while (k == 0 && !q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};

int main () {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution s;

    s.distanceK(root, root->left, 1);
}