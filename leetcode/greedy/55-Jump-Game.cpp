#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        int i = 0;

        while (i <= maxIdx) {
            maxIdx = max(maxIdx, i+nums[i]);
            i++;
            if (maxIdx >= nums.size()-1) return true;
        }
        return false;
    }
};
