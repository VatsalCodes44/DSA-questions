#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int r = sum%k;
            if (r==0 && i > 0) {
                return true;
            }
            if (mpp.find(r) != mpp.end()) {
                int n = i - mpp[r];
                if (n >= 2) return true;
            }
            else {
                mpp[r] = i;
            }

            
        }
        return false;
    }
};