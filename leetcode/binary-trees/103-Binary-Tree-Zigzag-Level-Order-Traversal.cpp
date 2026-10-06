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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ansArr;
        if (!root) return ansArr;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool zigzag = true;
        while (!dq.empty()) {
            int n = dq.size();
            vector<int> ans;
            ans.reserve(n);
            for (int i = 0; i < n; i++) {
                TreeNode* curr = zigzag ? dq.front() : dq.back();
                if (zigzag) dq.pop_front();
                else dq.pop_back();
                ans.push_back(curr->val);
                if (zigzag) {
                    if (curr->left) dq.push_back(curr->left);
                    if (curr->right) dq.push_back(curr->right);
                }
                else {
                    if (curr->right) dq.push_front(curr->right);
                    if (curr->left) dq.push_front(curr->left);
                }
            }
            ansArr.push_back(ans);
            zigzag ^= 1;
        }
        return ansArr;
    }
};