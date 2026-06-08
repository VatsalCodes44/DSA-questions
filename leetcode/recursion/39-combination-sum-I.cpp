#include <bits/stdc++.h>

using namespace std;

void cS(vector<int> &arr, vector<vector<int>> &ansArr, int i, int sum, int k, vector<int> &ans) {
    if (sum > k) return;
    if (sum == k) {
        ansArr.push_back(ans);
        return;
    }
    if (i == arr.size()) return;

    sum += arr[i];
    ans.push_back(arr[i]);
    cS(arr, ansArr, i, sum, k, ans);
    ans.pop_back();
    sum-= arr[i];

    cS(arr, ansArr, i+1, sum, k, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ansArr;
    vector<int> ans;
    cS(candidates, ansArr, 0, 0, target, ans);
    return ansArr;        
}

int main () {
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> arr = combinationSum(candidates, 7);

    for (auto i: arr) {
        for (int j = 0; j < i.size(); j++) {
            cout << i[j] << " ";
        }
        cout << endl;
    }
}