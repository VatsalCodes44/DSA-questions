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

class RecursiveInorder {
   public:
    void f(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;
        if (root->left)
            f(root->left, arr);
        arr.push_back(root->val);
        if (root->right)
            f(root->right, arr);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        f(root, ans);
        return ans;
    }
};

class RecursivePreorder {
public:
void f(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;
        arr.push_back(root->val);
        if (root->left)
            f(root->left, arr);
        if (root->right)
            f(root->right, arr);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        f(root, ans);
        return ans;
    }
};

class RecursivePostorder {
public:
    void f(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;
        if (root->left)
            f(root->left, arr);
        if (root->right)
            f(root->right, arr);
        arr.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        f(root, ans);
        return ans;
    }
};

class iterativeInorder {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        TreeNode* mover = root;
        stack<TreeNode*> st;
        while (mover || !st.empty()) {
            if (mover) {
                st.push(mover);
                mover = mover->left;
            }
            else {
                TreeNode* top = st.top();
                st.pop();
                ans.push_back(top->val);
                mover = top->right;
            }
        }
        return ans;
    }
};