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
private: 
    void bfsLevelorder(vector<TreeNode*>& currLevel, vector<vector<int>>& ansArr) {
        if (currLevel.size() == 0) return;

        vector<int> ans;
        vector<TreeNode*> nextLevel;
        for (int i = 0; i < currLevel.size(); i++) {
            if (currLevel[i]) {
                ans.push_back(currLevel[i]->val);
                nextLevel.push_back(currLevel[i]->left);
                nextLevel.push_back(currLevel[i]->right);
            }
        }
        if (ans.size() > 0) ansArr.push_back(ans);
        bfsLevelorder(nextLevel, ansArr);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ansArr;
        vector<TreeNode*> arr;
        arr.push_back(root);
        bfsLevelorder(arr, ansArr);
        return ansArr;
    }
};