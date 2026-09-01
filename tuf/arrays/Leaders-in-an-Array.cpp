#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      vector<int> ans;
      int nge = nums[nums.size()-1];
      ans.push_back(nge);
      for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] > nge) {
            ans.push_back(nums[i]);
            nge = nums[i];
        }
      }

      reverse(ans.begin(), ans.end());
      return ans;
    }
};