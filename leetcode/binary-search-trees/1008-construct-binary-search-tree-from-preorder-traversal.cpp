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

class Solution {
public:
    TreeNode* f(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode(preorder[l]);
        int pivot = l+1;
        for (pivot; pivot <=r; pivot++) if (preorder[pivot] > preorder[l]) break;
        root->left = f(preorder, l+1, pivot-1);
        root->right = f(preorder, pivot, r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return f(preorder, 0, preorder.size()-1);
    }
};