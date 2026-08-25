#include <bits/stdc++.h>

using namespace std;

int f(vector<int> & arr, int i, int k) {
    if (k < 0) return 0; 
    if (i == arr.size()) {
        if (k == 0) return 1;
        return 0;
    }

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