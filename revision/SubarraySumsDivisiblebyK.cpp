#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int count = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int r = ((sum%k)+k)%k;
            if (mpp.find(r) != mpp.end()) {
                count += mpp[r];
            }
            mpp[r]++;
        }
        return count;
    }
};