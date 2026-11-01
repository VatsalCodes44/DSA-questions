#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f (vector<int>& nums, int k) {
        int l = 0; int r = 0;
        int count = 0;
        int subs = 0;
        while (r < nums.size()) {
            if (nums[r]%2) count++;

            while (count > k) {
                if (nums[l]%2) count--;
                l++;
            }
            subs += r-l+1;
            r++;
        }
        return subs;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};