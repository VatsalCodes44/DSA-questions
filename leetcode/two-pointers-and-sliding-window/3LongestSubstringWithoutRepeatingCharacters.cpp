#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, maxLen = 0;
        int hash[256] = {0};

        while (r < s.size()) {
            while (hash[s[r]] > 0) {
                hash[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            hash[s[r]]++;
            r++;
        }

        return maxLen;
    }
};