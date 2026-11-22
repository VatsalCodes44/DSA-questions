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
    TreeNode* f(vector<int>& preorder, vector<int>& inorder, int rootIdx, int inLeft, int inRight) {
        if (inLeft > inRight)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[rootIdx]);
        int inPivot;
        for (inPivot = inLeft; inPivot <= inRight; inPivot++) {
            if (preorder[rootIdx] == inorder[inPivot])
                break;
        }
        int sizeLeft = (inPivot - 1) - inLeft + 1;
        int sizeRight = inRight - (inPivot + 1) - 1;
        TreeNode* left = f(preorder, inorder, rootIdx + 1 , inLeft, inPivot - 1);
        TreeNode* right = f(preorder, inorder, (rootIdx + 1) + sizeLeft -1 + 1, inPivot + 1, inRight);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return f(preorder, inorder, 0, 0, preorder.size()-1);
    }
};