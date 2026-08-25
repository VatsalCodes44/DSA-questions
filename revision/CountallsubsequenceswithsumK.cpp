#include <bits/stdc++.h>

using namespace std;

int f(vector<int> & arr, int i, int k) {
    if (k == 0) return 1; // this optimization anly works if the arr do noty have zeros
    if (i == arr.size()) return 0;

    // pick
    k -= arr[i];
    int l = f(arr, i+1, k);
    k += arr[i];

    int r = f(arr, i+1, k);

    return l+r;
}

int main () {
    vector<int> arr = {4, 9, 2, 5, 1};
    cout << f(arr, 0, 10);
}