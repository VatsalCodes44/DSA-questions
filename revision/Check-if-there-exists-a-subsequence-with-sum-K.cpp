#include <bits/stdc++.h>

using namespace std;

bool f(vector<int> & arr, int i, int k) {
    if (k == 0) return true; 
    if (i == arr.size()) return false;

    // pick
    k -= arr[i];
    if (f(arr, i+1, k)) return true;
    k += arr[i];

    return f(arr, i+1, k);
}

int main () {
    vector<int> arr = {4, 9, 2, 5, 1};
    cout << f(arr, 0, 10);
}