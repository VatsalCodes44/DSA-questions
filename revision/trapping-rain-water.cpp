#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ngeR = 0, ngeL = 0, sum = 0, l = 0, r = height.size()-1;

        while (l <= r) {
            if (height[l] <= height[r]) {
                if (ngeL >= height[l]) {
                    sum += ngeL - height[l];
                }
                else {
                    ngeL = height[l];
                }
                l++;
            }
            else {
                if (ngeR >= height[r]) {
                    sum += ngeR - height[r];
                }
                else {
                    ngeR = height[r];
                }
                r--;
            }
        }
        return sum;
    }
};

int main () {
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(arr);
}