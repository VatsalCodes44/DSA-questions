#include <bits/stdc++.h>

using namespace std;

void sS(vector<int> arr, int i, int sum, vector<int> ans) {
    if (i == arr.size()) {
        ans.push_back(sum);
        return;
    }

    sum += arr[i];
    sS(arr, i+1, sum, ans);
    sum -= arr[i];

    sS(arr, i+1, sum, ans);
}

vector<int> subsetSums(vector<int>& nums) {
    vector<int> ans;
    sS(nums, 0, 0, ans);
    return ans;
}