#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void f(vector<int> &arr, int i, int k, vector<int>& ans, vector<vector<int>>& ansArr) {
        if (k<0) return;
        if (k == 0) ansArr.push_back(ans);
        if (i == arr.size()) {
            return;
        }


        for (int j = i; j < arr.size(); j++) {
            if (j > i && arr[j] == arr[j-1]) continue;
            k -= arr[j];
            ans.push_back(arr[j]);
            f(arr, j+1, k, ans, ansArr);
            ans.pop_back();
            k += arr[j];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr(51, 0);
        for (auto i: candidates) {
            arr[i]++;
        }

        int idx = 0;
        for (int i = 1; i < 51; i++) {
            for (int j = 0; j < arr[i]; j++) {
                candidates[idx] = i;
                idx++;
            }
        }

        vector<int> ans;
        vector<vector<int>> ansArr;

        f(candidates, 0, target, ans, ansArr);

        return ansArr;
    }
};

int main () {
    vector <int> arr = {2,5,2,1,2};
    Solution s;
    s.combinationSum2(arr, 5);
}