#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int l = 0, h = nums.size()-1;
        int floor = -1, ceil = -1;
        while (l <= h) {
            int mid = (l+h)/2;
            if (nums[mid] <= x) {
                floor = mid;
                l= mid+1;
            }
            else {
                h = mid-1;
            }
        }

        l = 0, h = nums.size()-1;
        while (l <= h) {
            int mid = (l+h)/2;
            if (nums[mid] < x) {
                l = mid+1;
            }
            else {
                h = mid-1;
                ceil = mid;
            }
        }

        vector<int> ans = {floor == -1 ? -1 : nums[floor], ceil == -1 ? -1 : nums[ceil]};
        return ans;
    }
};