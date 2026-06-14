#include <bits/stdc++.h>

using namespace std;

int countSub(vector<int>& arr, int i, int k){
    if (k < 0) return 0;
    if (i == arr.size()) {
        if (k == 0) return 1;
        return 0;
    }

    k -= arr[i];
    int right = countSub(arr, i+1, k);
    k+= arr[i];

    int left = countSub(arr, i+1, k);
    return left + right;
}

int main () {
    vector<int> arr = {4, 9, 2, 5, 1};
    cout << countSub(arr, 0, 10) << endl;
}