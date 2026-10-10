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

class BFS{
    public:
    vector<int> topView(TreeNode *root){
        //your code goes here
        vector<int> ans;
        if(!root) return ans;
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [curr, verticle] = q.front();
                if (mpp.find(verticle) == mpp.end()) mpp[verticle] = curr->data;
                q.pop();
                if (curr->left) q.push({curr->left, verticle-1});
                if (curr->right) q.push({curr->right, verticle+1});
            }
        }

        for (auto &[_, val]: mpp){
            ans.push_back(val);
        }
        return ans;
    }
};