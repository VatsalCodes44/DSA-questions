#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int pS = nums[0];
        ans[0] = pS;
        for (int i = 1; i < nums.size(); i++) {
            pS *= nums[i];
            ans[i] = pS;
        }

        int sS = nums[nums.size()-1];
        ans[nums.size()-1] = ans[nums.size()-2];
        for (int i = nums.size()-2; i > 0; i--) {
            ans[i] = ans[i-1]*sS;
            sS *= nums[i];
        }
        ans[0] = sS;

        return ans;

    }
};