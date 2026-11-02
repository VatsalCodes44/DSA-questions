#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        int startIdx = 0;
        int minLen = INT_MAX;
        for (int i = 0; i < t.size(); i++) mpp[t[i]]++;

        for(int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mppCopy = mpp;
            int count = 0;
            for (int j = i; j < s.size(); j++) {
                if (mppCopy[s[j]] > 0) {
                    count++;
                }
                mppCopy[s[j]]--;
                if (count == t.size()) {
                    if (j-i+1 < minLen) {
                        startIdx = i;
                        minLen = j-i+1;
                    }
                    break;
                }
            }
        }
        string ans = "";
        if (minLen == INT_MAX) return ans;
        for (int i = 0; i < minLen; i++) ans += s[startIdx + i];
        return ans;
    }
};