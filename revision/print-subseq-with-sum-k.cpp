#include <bits/stdc++.h>

using namespace std;

void approach1 (vector<int>& arr, int i, int target, vector<int>& ans) {
    if (target < 0) return;
    if (i == arr.size()) {
        if (target == 0) {
            for (auto x: ans) {
                cout << x << " "; 
            }
            cout << endl;
            return;
        }
        return;
    }

    ans.push_back(arr[i]);
    target -= arr[i];
    approach1(arr, i+1, target, ans);
    ans.pop_back();
    target += arr[i];

    approach1(arr, i+1, target, ans);
}

void approach2 (vector<int>& arr, int i, int target, vector<int>& ans) {
    if (target < 0) return;
    if (target == 0) {
        for (auto x: ans) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    if (i == arr.size()) return;

    for (int j = i; j < arr.size(); j++) {
        ans.push_back(arr[j]);
        target -= arr[j];
        approach2(arr, j+1, target, ans);
        ans.pop_back();
        target += arr[j];
    }
}

int main () {
    vector<int> arr = {1,2,3};
    vector<int> ans;
    approach2(arr, 0, 3, ans);
}
