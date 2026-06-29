#include <bits/stdc++.h>

using namespace std;

void f (vector<int>& arr, int i, int target, vector<int>& ans) {
    if (target < 0) return;
    if (target == 0) {
        for (auto x: ans) {
            cout << x << " "; 
        }
        cout << endl;
        return;
    }
    if (i == arr.size()) return;

    ans.push_back(arr[i]);
    target -= arr[i];
    f(arr, i+1, target, ans);
    ans.pop_back();
    target += arr[i];

    f(arr, i+1, target, ans);
}

int main () {
    vector<int> arr = {1,2,3};
    vector<int> ans;
    f(arr, 0, 3, ans);
}