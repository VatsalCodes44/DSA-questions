#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int l = 0, r = 0;
        int count = 0;
        while (r < nums.size()) {
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                if (mpp[nums[l]] == 1)
                    mpp.erase(nums[l]);
                else
                    mpp[nums[l]]--;
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k - 1);
    }
};