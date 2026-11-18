#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class RecursiveInorder {
   public:
    void f(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        if (root->left) f(root->left, arr);
        arr.push_back(root->data);
        if (root->right) f(root->right, arr);
    }
    vector<int> inorder(TreeNode* root) {
        vector<int> ans;
        f(root, ans);
        return ans;
    }
};