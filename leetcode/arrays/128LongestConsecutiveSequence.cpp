#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for (auto i: nums) {
            st.insert(i);
        }

        int maxLen = 0;
        for (auto i: st) {
            if (st.find(i-1) == st.end()) {
                int count = 0;
                int j = i;
                while (st.find(j) !=st.end()) {
                    count++;
                    j++;
                }
                maxLen = max(maxLen, count);
            }
        }

        return maxLen;
    }
};