#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256,0), freqCopy(256,0);
        int startIdx = 0;
        int minLen = INT_MAX;
        int count = 0;
        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]++;
            freqCopy[t[i]]++;
        }

        int l = 0, r = 0;

        while (r < s.size()) {
            if (freq[s[r]] > 0)
                count++;
            freq[s[r]]--;
            while (count == t.size()) {
                if (r-l+1 < minLen) {
                    startIdx = l;
                    minLen = r - l + 1;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0 && freqCopy[s[l]] > 0)
                    count--;
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};