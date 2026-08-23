#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int prod = 1;
        int count = 0;

        int i = 0, j = 0;

        while (j < nums.size()) {
            prod *= nums[j];

            while (prod>=k && i < j) {
                int n = (j-1)-i+1;
                int modifiedI = 1;
                count += modifiedI * (n-modifiedI+1);
                prod /= nums[i];
                i++;
            }

            if (prod >= k) {
                count++;
                prod /= nums[i];
                i++;
            }
            j++;
        }
        while (i < j) {
            int n = (j-1)-i+1;
            int modifiedI = 1;
            count += modifiedI * (n-modifiedI+1);
            prod /= nums[i];
            i++;
        }
        return count;
    }
};