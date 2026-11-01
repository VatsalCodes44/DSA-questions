#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        if (k == 0) return -1;
        vector<int> copy = nums;
        sort(nums.begin(), nums.end());
        int locks = 0;
        int swaps = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != copy[i]) {
                if (locked[i]) locks++;
            }
        }
        for (int i = 0; i < nums.size()-1; i++) {
            if (abs(nums[i]-nums[i-1]) == 1)swaps++;
            else swaps+=2;
        }
        return locks+swaps;
    }
};
int main () {
    Solution s;
    vector<int> arr = {3,1,2};
    vector<int> locks = {1,0,1};
    cout << s.minOperations(arr, locks, 2);
}