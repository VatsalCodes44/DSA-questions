#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;
        int count = 0;
        while (j < s.size()) {
            if (i == g.size()) break;
            if (s.at(j) >= g.at(i)) {
                i++;
                count++;
            }
            j++;
        }

        return count;
    }
};