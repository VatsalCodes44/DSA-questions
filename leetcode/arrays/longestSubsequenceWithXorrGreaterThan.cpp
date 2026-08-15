#include <bits/stdc++.h>

using namespace std;

int longestSubsequence(vector<int>& nums) {
    int xorr = 0;
    int ans = 0;
    for (auto i: nums) {
        xorr^=i;
    }
    if (xorr > 0) return xorr;
    ans = nums.size();
    for (auto i: nums) {
        xorr^=i;
        ans--;
        if (xorr>0) break;
    }
    return ans;
}
int main () {
    vector <int> arr = {1,2,3};
    cout << longestSubsequence(arr);
}