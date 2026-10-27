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