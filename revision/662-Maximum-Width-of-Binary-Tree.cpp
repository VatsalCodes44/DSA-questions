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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<long long, TreeNode*>> q;
        q.push({0, root});
        long long maxWidth = 1;

        while (!q.empty()) {
            long long n = q.size();
            long long start = q.front().first;
            long long end = start;
            for (long long i = 0; i < n; i++) {
                auto [idx, curr] = q.front();
                q.pop();
                end = idx;
                idx -= start;
                if (curr->left) q.push({idx*2+1, curr->left});
                if (curr->right) q.push({idx*2+2, curr->right});
            }
            maxWidth = max(maxWidth, end-start+1);
        }
        return maxWidth;
    }
};