#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool overlapping(int b1, int a2) { return b1 >= a2; }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        // ans.reserve(intervals.size());

        if (intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }

        bool conflicted = false;
        if (newInterval[1] < intervals[0][0]) {
            conflicted = true;
            ans.push_back(newInterval);
        }


        int i = 0;
        for (i; i < intervals.size(); i++) {
            ans.push_back(intervals[i]);
            if (!conflicted && overlapping(ans.back()[1], newInterval[0])) {
                conflicted = true;
                break;
            }
            else if (!conflicted && ans.size() > 0 && i < intervals.size()-1 && ans.back()[1] < newInterval[0] && newInterval[1] < intervals[i+1][0]) {
                conflicted = true;
                ans.push_back(newInterval);
            }
        }

        if (i == intervals.size()) {
            if (!conflicted) ans.push_back(newInterval);
            return ans;
        }

        ans[ans.size()-1][0] = min(ans.back()[0], newInterval[0]);
        ans[ans.size()-1][1] = max(ans.back()[1], newInterval[1]);
        i++;

        for (i; i < intervals.size(); i++) {
            if (overlapping(ans.back()[1], intervals[i][0])) {
                ans[ans.size()-1][0] = min(ans.back()[0], intervals[i][0]);
                ans[ans.size()-1][1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};