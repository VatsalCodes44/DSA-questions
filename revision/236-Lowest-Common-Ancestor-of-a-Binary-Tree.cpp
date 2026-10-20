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
    bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& ancestors) {
        if (!root)
            return false;
        if (root == target) {
            ancestors.push_back(target);
            return true;
        }
        ancestors.push_back(root);
        if (dfs(root->left, target, ancestors))
            return true;
        if (dfs(root->right, target, ancestors))
            return true;
        ancestors.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pA;
        vector<TreeNode*> qA;
        dfs(root, p, pA);
        dfs(root, q, qA);
        for (int i = qA.size() - 1; i >= 0; i--) {
            for (int j = pA.size() - 1; j >= 0; j--) {
                if (qA[i] == pA[j]) return qA[i];
            }
        }
        return root;
    }
};

class SolutionO1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
};