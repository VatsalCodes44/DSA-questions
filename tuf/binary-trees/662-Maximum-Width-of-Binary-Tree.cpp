#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<long long, TreeNode*>> q;
        q.push({0, root});
        long long maxWidth = 1;

        while (!q.empty()){
            long long n = q.size();
            long long first = q.front().first;
            long long last = first;
            for (int i = 0; i < n; i++) {
                auto [idx, curr] = q.front();
                q.pop();
                last = idx;
                idx -= first;
                if (curr->left) q.push({2*idx+1, curr->left});
                if (curr->right) q.push({2*idx+2, curr->right});
            }
            maxWidth = max(maxWidth, last - first + 1);
        }

        return maxWidth;
    }
};

int main () {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(2);

    Solution s;
    cout << s.widthOfBinaryTree(root);
}