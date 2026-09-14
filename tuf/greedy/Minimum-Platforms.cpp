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
        vector<pair<int,int>> trains;
        trains.reserve(arr.size());
        
        for (int i = 0; i < arr.size(); i++) {
            trains.push_back({arr[i], dep[i]});
        }
        
        sort(trains.begin(), trains.end(), comparator);
        
        vector<pair<int, int>> platforms;
        platforms.reserve(arr.size());
        
        for (int i = 0; i < trains.size(); i++) {
            bool placed = false;
            for (int j = 0; j < platforms.size(); j++) {
                if (platforms[j].second < trains[i].first) {
                    placed = true;
                    platforms[j] = trains[i];
                    break;
                }
            }
            if (!placed) {
                platforms.push_back(trains[i]);
            }
        } 
        
        return platforms.size();
        
    }
};
