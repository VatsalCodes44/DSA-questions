#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> &vec) {
    for (auto i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

void subSeq(vector<int> &arr, int i, vector<int>& ans) {
    if (i == arr.size()) {
        printVec(ans);
        return;
    }

    // pick
    ans.push_back(arr[i]);
    subSeq(arr, i+1, ans);
    ans.pop_back();

    // not pick
    subSeq(arr, i+1, ans);
}

int main () {
    vector<int> arr = {1,2,3};
    vector<int> ans;

    subSeq(arr, 0, ans);
}