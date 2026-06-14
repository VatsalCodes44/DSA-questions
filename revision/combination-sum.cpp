#include <bits/stdc++.h>

using namespace std;

void cS(vector<int> &arr, vector<int> &ans, vector<vector<int>>&ansArr, int i, int k) {
    if ( k < 0) return;
    if (k == 0) {
        ansArr.push_back(ans);
        return;
    }
    if (i == arr.size()) return;

    k -= arr[i];
    ans.push_back(arr[i]);
    cS(arr, ans, ansArr, i, k);
    ans.pop_back();
    k += arr[i];

    cS(arr, ans, ansArr, i+1, k);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ansArr;
    vector<int> ans;
    cS(candidates, ans, ansArr, 0, target);
    return ansArr;
}