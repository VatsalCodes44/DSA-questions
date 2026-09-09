#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int j = 0;
        int i = 0;
        while (i < s.size()) {
            if (count == g.size()) break;
            if (s[i] >= g[j]) {
                j++;
                count++;
            }
            i++;
        }

        return count;
    }
};