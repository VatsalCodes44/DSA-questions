#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(255, -1);
        int l = 0;
        int r = 0;
        int maxLen = 0;
        while (r < s.size()) {
            if (freq[s[r]] >= l) {
                l = freq[s[r]]+1;
            }
            
            freq[s[r]] = r;
            
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};