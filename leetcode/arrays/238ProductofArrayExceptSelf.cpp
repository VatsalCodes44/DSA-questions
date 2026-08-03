#include <bits/stdc++.h>

using namespace std;

vector<int> bruteForce (vector<int>& nums) {
    vector<int> prefix(nums.size(), 0);
    vector<int> suffix(nums.size(), 0);
    prefix[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        prefix[i] = nums[i]*prefix[i-1];
    }
    suffix[nums.size()-1] = nums[nums.size()-1];
    for (int i = nums.size()-2; i >= 0; i--) {
        suffix[i] = suffix[i+1]*nums[i];
    }

    vector<int> ans(nums.size(),0);
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) {
            ans[0] = suffix[1];
        }
        else if (i == nums.size()-1) {
            ans[nums.size()-1] = prefix[nums.size()-2];
        }
        else {
            ans[i] = prefix[i-1]*suffix[i+1];
        }
    }
    return ans;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int prefix = nums[0];
    vector<int> ans(nums.size(),0);
    for (int i = 1; i < nums.size(); i++) {
        ans[i] = prefix;
        prefix*=nums[i];
    }
    int n = nums.size();
    int suffix = nums[n-1];
    for (int i = n-2; i > 0; i--) {
        ans[i] = ans[i]*suffix;
        suffix*=nums[i];
    }
    ans[0] = suffix;

    return ans;
}