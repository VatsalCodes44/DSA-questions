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
    TreeNode* f(unordered_map<int, int>& inorder, vector<int>& postorder, int rootIdx, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;
        TreeNode* root = new TreeNode(postorder[rootIdx]);
        int pivot = inorder[postorder[rootIdx]];
        int leftSize = pivot-inLeft;
        int rightSize = inRight-pivot;
        root->left = f(inorder, postorder, rootIdx-rightSize-1, inLeft, pivot-1);
        root->right = f(inorder, postorder, rootIdx-1, pivot+1, inRight);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return f(mpp, postorder, postorder.size()-1, 0, inorder.size()-1);
    }
};