#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0;
        int maxLen = 0;
        int l = 0;
        int r = 0;
        vector<int> hash(26, 0);
        while (r < s.size()) {
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq, hash[s[r]-'A']);
            int changes = r-l+1 - maxFreq;
            if (changes > k) {
                hash[s[l]-'A']--;
                l++;
                maxFreq = 0;
                changes = r-l+1 - maxFreq;
            }
            if (changes <= k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};