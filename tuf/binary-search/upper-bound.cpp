#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int l = 0, h = nums.size()-1;
        int res = nums.size();
        while (l <= h) {
            int mid = (l+h)/2;
            if (nums[mid] <= x) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
                res = mid;
            }
        }
        return res;
    }
};