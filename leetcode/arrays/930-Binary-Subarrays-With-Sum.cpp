#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
// prefix sum
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) count++;
            if (mpp[sum-k]) count+=mpp[sum-k];
            mpp[sum]++;
        }
        return count;
    }
};
// [1,0,1,0,1]
// [1,1,2,2,3]