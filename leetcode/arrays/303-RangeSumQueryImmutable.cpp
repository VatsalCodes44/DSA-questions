#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum = vector<int>(nums.size());
        prefixSum[0] = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            prefixSum[i] = sum;
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? prefixSum[right] : prefixSum[right] - prefixSum[left-1];
    }
};