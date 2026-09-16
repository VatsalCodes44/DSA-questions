#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        vector<vector<int>> arr;
        
        for (int i = 0; i < s.size(); i++) {
            vector<int> x = {i+1, s[i], f[i]};
            arr.push_back(x);
        }
        
        sort(arr.begin(), arr.end(), [](vector<int>&a, vector<int>& b) {
            return a[2] < b[2];
        });
        
        vector<int> ans;
        
        ans.push_back(arr[0][0]);
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][1] > f[ans.back()-1]) {
                ans.push_back(arr[i][0]);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};