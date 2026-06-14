#include <bits/stdc++.h>

using namespace std;

void cS2(vector<int> &arr, vector<int>& ans, vector<vector<int>>& ansArr, int i, int k) {
    if (k < 0) return;
    if (k == 0) {
        ansArr.push_back(ans);
        return;
    }
    if (i == arr.size()) return;
    int last = -1;
    for (int j = i; j < arr.size(); j++) {
        if (arr[j] == last) continue;

        ans.push_back(arr[j]);
        k -= arr[j];
        cS2(arr, ans, ansArr, j+1, k);
        k += arr[j];
        ans.pop_back();
        last = arr[j];
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ansArr;
    vector<int> ans;
    sort(candidates.begin(), candidates.end());
    cS2(candidates, ans, ansArr, 0, target);
    return ansArr;
}