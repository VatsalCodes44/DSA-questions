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
    // <minCol, maxCol>
    pair<int, int> f(TreeNode* root, int r, int c, vector<vector<int>>& ansArr) {
        if (!root) return {INT_MAX, INT_MIN};
        vector<int>ans = {r, c, root->val};
        ansArr.push_back(ans);
        auto [minColL, maxColL] = f(root->left, r+1, c-1, ansArr);
        auto [minColR, maxColR] = f(root->right, r+1, c+1, ansArr);

        return {min(min(minColL, minColR), c), max(max(maxColL, maxColR), c)};
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ansArr;
        auto [minC, maxC] = f(root, 0, 0, ansArr);
        vector<vector<int>> ans(abs(minC)+maxC+1);
        
        int absMinC = abs(minC);
        sort(ansArr.begin(), ansArr.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[2] < b[2];
        });
        for (int i = 0; i < ansArr.size(); i++) {
            int r = ansArr[i][0], c = ansArr[i][1], val = ansArr[i][2];
            ans[absMinC + c].push_back(val);
        }
        return ans;
    }
};