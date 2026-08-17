#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0, rmax = 0, total = 0;
        int l = 0;
        int r = height.size()-1;
        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] < lmax) {
                    total += lmax-height[l];
                }
                else {
                    lmax = height[l];
                }
                l++;
            }
            else {
                if (height[r] < rmax) {
                    total += rmax-height[r];
                }
                else {
                    rmax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};

int main () {
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(arr) << endl;
}