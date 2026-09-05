#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int l = 0, r = 0, count = 0, numOfOdd = 0;

        while (r < nums.size()) {
            numOfOdd += nums[r]%2;

            while (numOfOdd > k) {
                numOfOdd -= nums[l] % 2 == 1;
                l++;
            }

            if (numOfOdd <= k) count += r-l+1;
            r++;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};

int main () {
    Solution s;
    vector<int> nums = {1,1,2,1,1};
    cout << s.numberOfSubarrays(nums, 3) << endl;
}