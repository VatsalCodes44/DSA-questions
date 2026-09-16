#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0; int r = 0;
        int count = 0;
        while (r < nums.size()-1) {
            int newMax = 0;
            while (l <= r) {
                newMax = max(newMax, l+nums[l]);
                l++;
            }
            r = newMax;
            count++;
        }
        return count;
    }
};