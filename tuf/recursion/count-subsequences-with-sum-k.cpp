#include <bits/stdc++.h>

using namespace std;

int printSub(vector<int>& arr, int i, int sum, int k) {
    if (i == arr.size()) {
        if (sum == k) return 1;
        return 0;
    }

    int right = 0;
    sum += arr[i];
    if (sum <= k) {
        right = printSub(arr, i+1, sum, k);
    }
    sum -= arr[i];

    int left = printSub(arr, i+1, sum, k);

    return left + right; // no need just to avoid compiler warning of non void function
}

int main () {
    vector <int> arr = {1,2,3};
    cout << printSub(arr, 0, 0, 3) << endl;
}