#include <bits/stdc++.h>

using namespace std;

void subsequences(vector <int>& arr, int i, vector <int>& ans) {
    if (i == arr.size()) {
        for (int j = 0; j < ans.size(); j++) {
            cout << ans[j] << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(arr[i]);
    subsequences(arr, i+1, ans);
    ans.pop_back();
    subsequences(arr, i+1, ans);
}

int main () {
    vector <int> arr = {3,1,2};
    vector <int> ans;
    subsequences(arr, 0, ans);
}