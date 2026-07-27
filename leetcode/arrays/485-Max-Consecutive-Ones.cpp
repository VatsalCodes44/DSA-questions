#include <bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxC = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            count++;
            if (count > maxC) maxC = count;
        }
        else {
            count = 0;
        }
    }
    return maxC;
}