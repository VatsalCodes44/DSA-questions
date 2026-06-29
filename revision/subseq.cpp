#include <bits/stdc++.h>

using namespace std;

void approach1 (vector<int>& arr, int i, vector<int>& ans) {
    if (i == arr.size()) {
        for (auto i: ans) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    //pick
    ans.push_back(arr[i]); // make decision
    approach1(arr, i+1, ans); // explore
    ans.pop_back(); // undo

    // not pick
    approach1(arr, i+1, ans);
}

void approach2 (vector<int>& arr, int i, vector<int>& ans) {
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << endl;

    if (i == arr.size()) return;
    
    for (int j = i; j < arr.size(); j++) {
        ans.push_back(arr[j]);
        approach2(arr, j+1, ans);
        ans.pop_back();
    }
}


int main () {
    vector<int> arr = {1, 2, 3};
    vector<int>ans;
    approach2(arr, 0, ans);
}