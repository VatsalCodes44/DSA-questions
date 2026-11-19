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
class iterativePreorder {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack <TreeNode*> st1;
        stack <TreeNode*> st2;
        st1.push(root);
        while (!st1.empty()) {
            TreeNode* top = st1.top();
            st1.pop();
            st2.push(top);
            if (top->left) st1.push(top->left);
            if (top->right) st1.push(top->right);
        }

        while (!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};

class morrisInorder {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* temp = curr->left;
                while (temp->right && temp->right != curr) temp = temp->right;
                
                if (temp->right == curr) {
                    temp->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                else {
                    temp->right = curr;
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
};

class morrisPreorder {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;

        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* temp = curr->left;
                while (temp->right && temp->right != curr)
                    temp = temp->right;

                if (temp->right == curr) {
                    temp->right = nullptr;
                    curr = curr->right;
                } else {
                    temp->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
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
class morrisPostorder {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        TreeNode* curr = root;
        while (curr) {
            if (!curr->right) {
                ans.push_back(curr->val);
                curr = curr->left;
            }
            else {
                TreeNode* temp = curr->right;
                while (temp->left && temp->left != curr) temp = temp->left;

                if (temp->left == curr) {
                    temp->left = nullptr;
                    curr = curr->left;
                }
                else {
                    temp->left = curr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class BFS {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; i++) {
                TreeNode* top = q.front();
                q.pop();
                level.push_back(top->val);
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};