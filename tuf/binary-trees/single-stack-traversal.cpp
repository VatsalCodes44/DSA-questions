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

void dfs(TreeNode* root) {
    vector<int> pre, in, post;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        TreeNode* top = st.top().first;
        int num = st.top().second;
        st.pop();
        if (num == 1) {
            pre.push_back(top->val);
            num++;
            st.push({top, num});
            if (top->left) st.push({top->left, 1});
        }
        else if (num == 2) {
            in.push_back(top->val);
            num++;
            st.push({top, num});
            if (top->right) st.push({top->right, 1});
        }
        else {
            post.push_back(top->val);
        }
    }

    for (int i: pre) {
        cout << i << " ";
    }
    cout << endl;

    for (int i: in) {
        cout << i << " ";
    }
    cout << endl;

    for (int i: post) {
        cout << i << " ";
    }
    cout << endl;
}

int main () {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    dfs(root);
}