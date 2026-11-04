#include <bits/stdc++.h>

using namespace std;

static const int speedup = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j == g.size()) break;
            if (g[j] <= s[i]) {
                count++;
                j++;
            }
        }
        return count;
    }
};