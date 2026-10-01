#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int count = 0;
        int j = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[j][1] > intervals[i][0]) count++;
            else j=i;
        }

        return count;
    }
};