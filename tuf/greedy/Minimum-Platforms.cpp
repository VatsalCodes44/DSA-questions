#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    static int comparator (pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    
    
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int count = 0;
        int maxCount = 0;
        
        int i = 0, j = 0;
        
        while (i < arr.size() && j < arr.size()) {
            if (arr[i] <= dep[j]) {
                count++;
                maxCount = max(maxCount, count);
                i++;
            }
            else {
                count--;
                j++;
            }
        }
        
        return maxCount;
    }
};
