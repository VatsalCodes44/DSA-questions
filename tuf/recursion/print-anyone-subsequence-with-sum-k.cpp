#include <bits/stdc++.h>

using namespace std;

bool printSub(vector<int> arr, int i, vector<int> &ans, int& sum, int k) {
    if (i == arr.size()) {
        if (sum == k) {
            for (int i : ans) {
                cout << i << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    sum += arr[i];
    if (sum <= k) {
        ans.push_back(arr[i]);
        if (printSub(arr, i+1, ans, sum, k)) return true;
        ans.pop_back();
    }
    sum -= arr[i];

    if (printSub(arr, i+1, ans, sum, k)) return true;
    return false; // no need just to avoid compiler warning of non void function
}

int main () {
    vector <int> arr = {1,2,3};
    vector<int> ans;
    int sum = 0;
    printSub(arr, 0, ans, sum, 3);
}