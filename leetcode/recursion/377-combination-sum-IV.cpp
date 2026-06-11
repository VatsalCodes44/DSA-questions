#include <bits/stdc++.h>

using namespace std;

int cS4(vector<int>&arr, int k) {
    if (k < 0) return 0;
    if (k==0) return 1;
    int sum = 0;
    for (int j = 0; j < arr.size(); j++) {
        k -= arr[j];
        sum += cS4(arr, k);
        k += arr[j];
    } 
    return sum;
}

int combinationSum4(vector<int>& nums, int target) {
    return cS4(nums, target);
}

int main () {
    vector <int>arr = {1,2,3};
    cout << combinationSum4(arr, 7) << endl;
}