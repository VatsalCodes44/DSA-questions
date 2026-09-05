#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int maxLen = 0;
        int l = 0, r = 0;
        vector<int> hash(256, 0);
        int count = 0;

        while (r < s.size()) {
            if (!hash[s[r]]) count++;
            hash[s[r]]++;
            if (count > k) {
                if (hash[s[l]] == 1) count--;
                hash[s[l]]--;
                l++;
            }
            if (count <= k) {
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};