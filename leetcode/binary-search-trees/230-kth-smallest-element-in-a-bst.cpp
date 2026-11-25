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
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        int left = kthSmallest(root->left, k);
        if (left != -1 && count != k)count++;
        if(count == k) return left;

        if (count != k)count++;
        if (count == k) return root->val;

        int right = kthSmallest(root->right, k);
        if (right != -1 && count != k)count++;
        if (count == k) return right;

        return -1;
    }
};