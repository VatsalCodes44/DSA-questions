#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mpp;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == goal) count++;
            if (mpp.find(sum-goal) != mpp.end()) {
                count += mpp[sum-goal];
            }

            mpp[sum]++;
        }
        return count;
    }
};