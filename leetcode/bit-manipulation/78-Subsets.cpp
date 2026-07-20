#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

    for (int i = 0; i < (1 << nums.size()); i++) {
        vector <int> arr;
        for (int j = 0; j < nums.size() ;j++) {
            if (i & (1 << j)) {
                arr.push_back(nums[j]);
            }
        }
        ans.push_back(arr);
    }

    return ans;
}

int main () {
    vector<int> a = {1,2,3};
    vector<vector<int>> arr = subsets(a);
    for (auto i : arr) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}