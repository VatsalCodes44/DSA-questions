#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& nums) {
    bool rotated = false;
    bool rotateIdx = 0;
    
    for (int i = 0; i < nums.size()-1; i++) {
        if (nums[i] > nums[i+1] && !rotated) {
            rotated = true;
            rotateIdx = i;
            continue;
        }
        else if (nums[i] > nums[i+1] && rotated) return false;

    }
    if (rotated && nums[rotateIdx] < nums[nums.size()-1]) return false;
    return true;
}