#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int i = 0;

        while (i <= maxReach) {
            maxReach = max(maxReach, i+nums[i]);
            if (maxReach >= nums.size()-1) return true;
            i++;
        }
        return false;
    }
};