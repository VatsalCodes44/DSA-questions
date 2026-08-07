#include <bits/stdc++.h>

using namespace std;

int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) nums[i] = -1;
        }

        int sum = 0;
        int len = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == 0) {
                len = max(len, i+1);
            }
            if (mpp.find(sum) != mpp.end()) {
                len = max(len, i-mpp[sum]);
                continue;
            }
            mpp[sum] = i;
        }
        return len;
}