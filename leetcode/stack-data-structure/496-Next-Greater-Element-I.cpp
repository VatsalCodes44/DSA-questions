#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums2.size(); i++) {
        mpp[nums2[i]] = i;
    }
    for (int i = 0; i < nums1.size(); i++) {
        int j = mpp[nums1[i]]+1;
        bool pushed = false;
        for (j; j < nums2.size(); j++) {
            if (nums1[i] < nums2[j]) {
                pushed = true;
                ans.push_back(nums2[j]);
                break;
            }
        }
        if (!pushed) {
            ans.push_back(-1);
        }
    }
    return ans;
}