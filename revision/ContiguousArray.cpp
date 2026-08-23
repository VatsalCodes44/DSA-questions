#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> mpp;
        int sum = 0;
        int maxLen = 0;
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;

            if (sum == 0) {
                maxLen = max(maxLen, i+1);
            }
            if (mpp.find(sum-k) != mpp.end()) {
                maxLen = max(maxLen, i-mpp[sum-k]);
            }
            else {
                mpp[sum] = i;
            }
        }
        return maxLen;
    }
};