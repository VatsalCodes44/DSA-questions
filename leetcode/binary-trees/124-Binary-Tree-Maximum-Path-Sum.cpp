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
    // {maxDownPath, currMaxPathTillNow}
    pair<long long, long long> f(TreeNode* root) {
        if (!root) return {INT_MIN,INT_MIN};
        auto [maxDownPathLeft, currMaxPathLeft] = f(root->left);
        auto [maxDownPathRight, currMaxPathRight] = f(root->right);
        long long currMaxPathTillNow = max(max(max(currMaxPathLeft, currMaxPathRight), (long long)root->val), maxDownPathLeft + maxDownPathRight + root->val);

        auto maxDownPath = max(max(maxDownPathLeft, maxDownPathRight) + root->val, (long long)root->val);
        return {maxDownPath, max(currMaxPathTillNow, maxDownPath)};
    }
    int maxPathSum(TreeNode* root) {
        if (!root->left && !root->right) return root->val;
        auto [maxDownPath, currMaxPathTillNow] = f(root);
        return max(maxDownPath, currMaxPathTillNow);
    }
};

int main () {
    TreeNode* root = new TreeNode(5);

    root->left  = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);          // 4's right is null
    root->left->left->left  = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left  = new TreeNode(13);        // 13 has no children
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);  // this 4's left is null

    Solution s;
    cout << s.maxPathSum(root) << endl;
}