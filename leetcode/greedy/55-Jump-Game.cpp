#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        int i = 0;

        do {
            if (maxIdx < i+nums[i]) maxIdx = i+nums[i];
            if (maxIdx >= nums.size()-1) return true;
            i++;
        } while (i <= maxIdx);
        
        return false;
    }
};
