#include <bits/stdc++.h>

using namespace std;

int approach1 (vector<int>& arr, int i, int k) {
    if (k < 0) return 0;
    if (i == arr.size()) {
        if (k == 0) return 1;
        return 0;
    }

    k -= arr[i];
    int left = approach1(arr, i+1, k);
    k += arr[i];
    
    int right = approach1(arr, i+1, k);

    return left + right;
}

int approach2 (vector<int>& arr, int i, int k) {
    if (k < 0) return 0;
    if (k == 0) return 1;
    if (i == arr.size()) return 0;

    int count= 0;
    
    for (int j = i; j < arr.size(); j++) {
        k -= arr[j];
        count += approach2(arr, j+1, k);
        k += arr[j];
    }
    
    return count;
}

int main () {
    vector<int> arr = {4, 9, 2, 5, 1};
    cout << approach2(arr, 0, 10) << endl;
}