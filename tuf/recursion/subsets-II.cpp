#include <bits/stdc++.h>

using namespace std;

void cS(vector<int> &arr, vector<vector<int>> &ansArr, int i, vector<int> &ans) {
    ansArr.push_back(ans);
    if (i == arr.size()) {
        return;
    };

    int last = -11;
    for (int j = i; j < arr.size(); j++) {
        if (arr[j] != last) {                
            ans.push_back(arr[j]);
            cS(arr, ansArr, j+1, ans);
            ans.pop_back();

            last = arr[j];
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> freq(21, 0);
    for (int i: nums) {
        freq[i+10]++;
    }
    int x = 0;
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < freq[i]; j++) {
            nums[x] = i-10;
            x++;
        }
    }
    vector<vector<int>> ansArr;
    vector<int> ans;
    cS(nums, ansArr, 0, ans);
    return ansArr;        
}