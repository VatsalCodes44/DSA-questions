#include <bits/stdc++.h>

using namespace std;

static const int speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1, b = -1, c = -1;
        int count = 0;
        int l = 0, r = 0;
        while (r < s.size()) {
            if (s[r] == 'a') a = r;
            else if (s[r] == 'b') b = r;
            else c = r;

            r++;

            int lastSeen = min(a, min(b,c));
            if (lastSeen == -1) continue;

            count += lastSeen+1;
        }
        return count;
    }
};
