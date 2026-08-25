#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void f(vector<int>& arr, int i, int k, vector<int>& ans, vector<vector<int>>& ansArr) {
        if (k < 0) return;
        if (i == arr.size()) {
            if (!k) ansArr.push_back(ans);
            return;
        }

        k -= arr[i];
        ans.push_back(arr[i]);
        f(arr, i, k, ans, ansArr);
        ans.pop_back();
        k += arr[i];

        f(arr, i+1, k, ans, ansArr);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> ansArr;
        f(candidates, 0, target, ans, ansArr);
        
        return ansArr;
    }
};