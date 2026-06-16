#include <bits/stdc++.h>

using namespace std;



int countSub2(vector<int>& arr, int i, int k, string& ans) {
    if (k < 0) return 0;
    if (k == 0) return 1;
    if (i == arr.size()) {
        return 0;
    }

    int count = 0;
    for (int j = i; j < arr.size(); j++) {
        k -= arr[j];
        ans.push_back('0'+arr[j]);
        count += countSub2(arr, j+1, k, ans);
        ans.pop_back();
        k += arr[j];
    }
    return count;
}

int main () {
    vector<int> arr = {4, 9, 2, 5, 1};
    string ans = "";
    cout << countSub2(arr, 0, 10, ans) << endl;
}