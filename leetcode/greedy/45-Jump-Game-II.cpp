#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int l = 0, r = 0;
        int jump = 0;
        while (l <= r) {
            if (r >= nums.size()-1) break;
            int minOutOfRange = 0;
            int maxOutOfRange = 0;
            for (int j = l; j <= r; j++) {
                if (j+nums[j] <= r) continue;
                else {
                    maxOutOfRange = max(maxOutOfRange, j+nums[j]);
                    minOutOfRange = r+1;
                }
            }
            r = maxOutOfRange;
            l = minOutOfRange;
            jump++;
        }
        return jump;
    }
};