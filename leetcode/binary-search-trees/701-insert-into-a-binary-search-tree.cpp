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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* mover = root;
        while (mover) {
            if (mover->val < val) {
                if (!mover->right) {
                    mover->right = new TreeNode(val);
                    break;
                }
                else mover = mover->right;
            }
            else {
                if (!mover->left) {
                    mover->left = new TreeNode(val);
                    break;
                }
                else mover = mover->left;
            }
        }
        return root;
    }
};