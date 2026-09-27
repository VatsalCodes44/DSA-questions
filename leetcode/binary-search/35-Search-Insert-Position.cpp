#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1;
        int res = -1;
        while (l <= h) {
            int mid = l + (h-l)/2;

            if (nums[mid] < target) {
                l = mid+1;
            }
            else {
                h = mid-1;
                res = mid;
            }
        }

        return res == -1 ? nums.size() : res;
    }
};