#include <bits/stdc++.h>

using namespace std;

int largestElement(vector<int>& nums) {
    int maxx = nums[0];
    for (auto i : nums) {
        if (maxx < i) {
            maxx = i;
        }
    }
    return maxx;
}