#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPositive = nums[0];
        int minNegative = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(maxPositive, minNegative);
            maxPositive = max(maxPositive*nums[i], nums[i]);
            minNegative = min(minNegative*nums[i], nums[i]);
            ans = max(ans, maxPositive);
        }
        return ans;
    }
};