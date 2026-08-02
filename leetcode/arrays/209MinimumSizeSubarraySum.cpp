#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int sum = 0;

        while (right < nums.size()) {
            sum += nums[right];
            
            while (sum >= target) {
                sum -= nums[left];
                minLen = min(minLen, right-left+1);
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};