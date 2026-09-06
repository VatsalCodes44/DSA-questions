#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int k) {
        if (k <= 0) return 0;
        unordered_map<int, int> hash;
        int l = 0, r = 0;
        int ans = 0;
        int count = 0;

        while (r < nums.size()) {
            if (hash[nums[r]] == 0) count++;
            hash[nums[r]]++;

            while (count > k) {
                if (hash[nums[l]] == 1) count--;
                hash[nums[l]]--;
                l++;
            }

            if (count <= k) {
                ans += r-l+1;
            }
            r++;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};