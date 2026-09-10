#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0;
        int t = 0;
        int r = matrix[0].size()-1;
        int d = matrix.size()-1;
        vector<int> ans;
        ans.reserve(matrix.size()*matrix[0].size());

        while (l <= r && t <= d) {
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            if (ans.size() == matrix.size()*matrix[0].size()) break;
            t++;
            for (int i = t; i <= d; i++) {
                ans.push_back(matrix[i][r]);
            }
            if (ans.size() == matrix.size()*matrix[0].size()) break;
            r--;
            for (int i = r; i >= l; i--) {
                ans.push_back(matrix[d][i]);
            }
            if (ans.size() == matrix.size()*matrix[0].size()) break;
            d--;
            for (int i = d; i >= t; i--) {
                ans.push_back(matrix[i][l]);
            }
            if (ans.size() == matrix.size()*matrix[0].size()) break;
            l++;
        }
        return ans;
    }
};