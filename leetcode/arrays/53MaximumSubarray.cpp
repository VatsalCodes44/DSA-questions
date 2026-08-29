#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestAns = nums[0];
        int bestTillPrev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int choice1 = bestTillPrev + nums[i];
            int choice2 = nums[i];

            bestTillPrev = max(choice1, choice2);
            bestAns = max(bestAns, bestTillPrev);
        }

        return bestAns;
    }
};