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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int maxW = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int start = -1;
            int currMax = 0;
            for (int i = 0; i < n; i++) {
                if (start == -1) {
                    if (!q.front()) {
                        q.pop();
                        continue;
                    }
                    else {
                        start = i;
                    }
                }
                
                if (q.front()) {
                    currMax = max(i-start+1, currMax);
                }

                TreeNode* curr = q.front();
                q.pop();
                if (!curr) {
                    q.push(nullptr);
                    q.push(nullptr);
                    continue;
                }
                if (curr->left) q.push(curr->left);
                else q.push(nullptr);
                if (curr->right) q.push(curr->right);
                else q.push(nullptr);
            }

            maxW = max(maxW, currMax);
        }
        return maxW;
    }
};
