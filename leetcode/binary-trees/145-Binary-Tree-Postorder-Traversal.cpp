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

class Recursive {
private:
    void dfsPostorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        dfsPostorder(root->left, ans);
        dfsPostorder(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfsPostorder(root, ans);
        return ans;
    }
};

class Iterative2Stacks {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> st1;
        st1.push(root);
        stack<TreeNode*> st2;

        while (!st1.empty()) {
            TreeNode* top = st1.top();
            st1.pop();
            st2.push(top);
            if (top->left) st1.push(top->left);
            if (top->right) st1.push(top->right);
        }        

        ans.reserve(st2.size());
        while (!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};