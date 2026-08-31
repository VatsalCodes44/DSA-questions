#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, maxLen = 0;
        vector<int> hash(256, -1);

        while (r < s.size()) {
            if (hash[s[r]] >= l) {
                l = hash[s[r]]+1;
            }

            maxLen = max(maxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};

int main () {
    Solution s;
    cout << s.lengthOfLongestSubstring("S") << endl;
}