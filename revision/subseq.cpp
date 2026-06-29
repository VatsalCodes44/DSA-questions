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

int main () {
    vector<int> arr = {1, 2, 3};
    vector<int>ans;
    approach1(arr, 0, ans);
}