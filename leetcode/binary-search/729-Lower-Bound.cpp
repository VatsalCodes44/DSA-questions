#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int l = 0, h = nums.size()-1;
        int mid = -1;
        while (l < h) {
            mid = (l+h)/2;
            if (nums[mid] >= x) {
                h = mid;
            } else {
                l = mid+1;
            }
        }
        return nums[l] >= x ? l : nums.size();
    }
};

int main () {
    vector<int> arr = {1,2,2,3};
    Solution s;
    cout << s.lowerBound(arr, 2);
}