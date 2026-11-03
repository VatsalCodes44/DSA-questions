#include <bits/stdc++.h>

using namespace std;

static const int speedup = []() {
    std::ios::sync_with_stdio();
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    string minWindow(string s, string t) {
        int count = 0;
        vector<int> freq(256, 0);
        int l = 0;
        int r = 0;
        int startIdx = 0;
        int minLen = INT_MAX;
        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]++;
        }

        while (r < s.size()) {
            if (freq[s[r]] > 0)
                count++;
            freq[s[r]]--;
            while (count == t.size()) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }
                if (freq[s[l]] == 0) {
                    count--;
                }
                freq[s[l]]++;
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
