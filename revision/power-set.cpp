#include <bits/stdc++.h>

using namespace std;

void powerSet(vector<int>& arr, vector<vector<int>>& ansArr) {
    int n = arr.size();
    for (int i = 0; i < (1<<n); i++) {
        vector<int> ans;
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) {
                ans.push_back(arr[j]);
            }
        }
        ansArr.push_back(ans);
    }
}

int main () {
    vector<int> arr = {1,2,3};
    vector<vector<int>> ansArr;

    powerSet(arr, ansArr);

    for (auto i: ansArr) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}