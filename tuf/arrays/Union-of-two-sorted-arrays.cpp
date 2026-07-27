#include <bits/stdc++.h>

using namespace std;

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    vector<int> ans;
    while (i < nums1.size() && j < nums2.size()) {
        if (ans.size() > 0) {
            if (nums1[i] == ans.back()) {
                i++; continue;
            }
            if (nums2[j] == ans.back()) {j++; continue;}
        }
        if (nums1[i] == nums2[j]) {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j]) {
            ans.push_back(nums1[i]);
            i++;
        }
        else {
            ans.push_back(nums2[j]);
            j++;
        }
    }

    while (i < nums1.size()) {
        if (ans.size() > 0) {
            if (nums1[i] == ans.back()){i++; continue;}
        }
        ans.push_back(nums1[i]);
        i++;
    }

    while (j < nums2.size()) {
        if (ans.size() > 0) {
            if (nums2[j] == ans.back()) {j++; continue;}
        }
        ans.push_back(nums2[j]);
        j++;
    }
    return ans;
}

int main () {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 7};

    for (auto i: unionArray(nums1, nums2)) {
        cout << i << " ";
    }
}