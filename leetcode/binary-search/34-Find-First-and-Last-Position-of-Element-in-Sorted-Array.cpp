#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1;
        int first = -1;
        int last = -1;
        while (l <= h) {
            int mid = (l+h)/2;
            if (nums[mid] < target) {
                l = mid+1;
            }
            else {
                first = mid;
                h = mid-1;
            }
        }

        if (first == -1 || nums[first] != target) {
            vector <int> ans = {-1,-1};
            return ans;
        }

        l = first;
        h = nums.size()-1;

        while (l <= h) {
            int mid = (l+h)/2;

            if (nums[mid] == target) {
                last = mid;
                l = mid+1;
            }
            else h = mid-1;
        }

        vector <int> ans = {first, last};
        return ans;
    }
};