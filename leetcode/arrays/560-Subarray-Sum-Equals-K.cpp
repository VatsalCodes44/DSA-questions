#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    map<int, int> prefSum;
    int i = 0;
    int sum = 0; 
    int maxLen = 0;

    while (i < nums.size()) {
        sum += nums[i];

        if (sum == k) {
            maxLen = max(maxLen, i+1);
        }

        if (prefSum.find(sum-k) != prefSum.end()) {
            maxLen = max(maxLen, i-prefSum[sum-k]);
        }

        if (nums[i] != 0) {
            prefSum[sum] = i;
        }
        i++;
    }

    return maxLen;
}

int subarraySumGreedy(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int sum = 0;
    int maxLen = 0;

    while (i < arr.size() && j < arr.size()) {

        if (sum == k) {
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        if (sum > k) {
            sum -= arr[i];
            i++;
        }
        else {
            sum+=arr[j];
            j++;
        }
    }

    return maxLen;
}

int main () {
    vector<int> nums = {1,0,0,0,1,5};
    cout << subarraySumGreedy(nums, 6) << endl;
}