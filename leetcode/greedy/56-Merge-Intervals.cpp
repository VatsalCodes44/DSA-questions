#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool overLap(int s1, int e1, int s2, int e2) {
        if (e1 < s2) return false;
        else return true;           
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        ans.reserve(intervals.size());
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (overLap(ans.back()[0], ans.back()[1], intervals[i][0], intervals[i][1])) {
                vector<int> arr = {min(ans.back()[0], intervals[i][0]), max(ans.back()[1], intervals[i][1])};
                ans.pop_back();
                ans.push_back(arr);
            }
            else ans.push_back(intervals[i]);
        }
        return ans;
        
    }
}
// 