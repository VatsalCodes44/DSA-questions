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

class Solution {
public:
    bool f(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if ((!p && q) || (p && !q)) return false;
        if (p->val != q->val) return false;
        if (!f(p->left, q->right)) return false;
        if (!f(p->right, q->left)) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return f(root->left, root->right);
    }
};