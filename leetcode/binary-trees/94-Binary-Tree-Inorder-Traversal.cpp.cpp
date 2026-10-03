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
    void dfsInorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        dfsInorder(root->left, ans);
        ans.push_back(root->val);
        dfsInorder(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfsInorder(root, ans);
        return ans;
    }
};

class Iterative {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* mover = root;

        while (!st.empty()) {
            if (mover) {
                if (mover->left) st.push(mover->left);
                mover = mover->left;
            }
            else {
                TreeNode* top = st.top();
                st.pop();
                mover = top->right;
                ans.push_back(top->val);
                if (top->right) st.push(top->right);
            }
        }
        return ans;
    }
};