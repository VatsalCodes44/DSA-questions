#include <bits/stdc++.h>

using namespace std;

bool countSub(vector<int>& arr, int i, int k, string& ans){
    if (k < 0) return false;
    if (i == arr.size()) {
        if (k == 0) {
            cout << ans << endl;
            return true;
        }
        return false;
    }

    k -= arr[i];
    ans.push_back('0'+arr[i]);
    if (countSub(arr, i+1, k, ans)) return true;
    ans.pop_back();
    k+= arr[i];

    return countSub(arr, i+1, k, ans);
}

bool countSub2(vector<int>& arr, int i, int k, string& ans) {
    if (k < 0) return 0;
    if (k == 0) {
        cout << ans << endl;
        return true;
    };
    if (i == arr.size()) {
        return 0;
    }

    bool isFound = false;
    for (int j = i; j < arr.size(); j++) {
        if (!isFound) {
            k -= arr[j];
            ans.push_back('0'+arr[j]);
            isFound = countSub2(arr, j+1, k, ans);
            ans.pop_back();
            k += arr[j];
        }
        else break;
    }
    return isFound;
}

int main () {
    vector<int> arr = {4, 9, 2, 5, 1};
    string ans = "";
    cout << countSub(arr, 0, 10, ans) << endl;
}