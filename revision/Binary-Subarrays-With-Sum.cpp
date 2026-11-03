#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumK(vector<int>& arr, int k) {
        if (k < 0) return 0;
        int l = 0, r = 0;
        int sum = 0;
        int count = 0;

        while (r < arr.size()) {
            sum += arr[r];
            while (sum > k) {
                sum -= arr[l];
                l++;
            }

            count += r-l+1;
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sumK(nums, goal) - sumK(nums, goal-1);
    }
};