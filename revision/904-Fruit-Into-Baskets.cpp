#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int count = 0;
        int l = 0, r = 0;
        int maxCount = 0;
        while (r < fruits.size()) {
            mpp[fruits[r]]++;
            count++;
            while (mpp.size() > 2) {
                if (mpp[fruits[l]] == 1) mpp.erase(fruits[l]);
                else mpp[fruits[l]]--;
                count--;
                l++;
            }
            maxCount = max(maxCount, count);
            r++;
        }
        return maxCount;
    }
};