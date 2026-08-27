#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void f(vector<int>& ans, vector<vector<int>>& ansArr, int i, int n, int sum) {
        if (sum < 0) return;
        if (ans.size() == n) {
            if (sum == 0) {
                ansArr.push_back(ans);
            }
            return;
        }
        if (ans.size() > n) return;

        for (int j = i; j <= 9; j++) {
            sum -= j;
            ans.push_back(j);
            f(ans, ansArr, j+1, n, sum);
            sum += j;
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        vector<vector<int>> ansArr;
        f(ans, ansArr, 1, k, n);
        return ansArr;
    }
};