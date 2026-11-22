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
    vector<int> floorCeilOfBST(TreeNode* root, int key) {
        // your code goes here
        vector<int> ans;
        int floor = INT_MIN;
        TreeNode* mover = root;
        while (mover) {
            if (mover->val <= key) {
                floor = max(floor, mover->val);
                mover = mover->right;
            }
            else mover = mover->left;
        }
        ans.push_back(floor == INT_MIN ? -1 : floor);

        mover = root;
        int ceil = INT_MAX;
        while(mover) {
            if (mover->val >= key) {
                ceil = min(ceil, mover->val);
                mover = mover->left;
            }
            else mover = mover->right;
        }
        ans.push_back(ceil == INT_MAX ? -1 : ceil);
        return ans;
    }
};