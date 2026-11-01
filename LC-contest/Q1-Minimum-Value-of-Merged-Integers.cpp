#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int minSum = INT_MAX;
        for (int i = 0; i < nums.size(); i += 2) {
            int a = nums[i];
            int b = nums[i+1];
            int n = 4;
            if (b < 10) n = 1;
            else if (b < 100) n = 2;
            else if (b < 1000) n = 3;

            for (int i = 0; i < n; i++) a*=10;
            minSum = min(minSum, a+b);
        }
        return minSum;
    }
};

int main () {
    vector<int> arr = {23,55,42,21};
    Solution s;
    cout << s.minMergedInteger(arr);
}