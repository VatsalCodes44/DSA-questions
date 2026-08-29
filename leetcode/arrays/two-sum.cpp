#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> freq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (freq.find(target-nums[i]) != freq.end()) {
                ans.push_back(freq[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            freq[nums[i]] = i;
        }
        return ans;
    }
};