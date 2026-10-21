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

class Solution{
	public:
        void f(TreeNode* root, vector<int>& path, vector<vector<int>>&ans){
            if (!root) {
                ans.push_back(path);
                return;
            }
            path.push_back(root->data);
            if (!root->left && !root->right) {
                f(root->left, path, ans);
            }
            else {
                if (root->left) f(root->left, path, ans);
                if (root->right) f(root->right, path, ans);
            }
            path.pop_back();
        }
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
            vector<vector<int>> ans;
            vector<int> path;
            f(root, path, ans);
            return ans;
		}
};