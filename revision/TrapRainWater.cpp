#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> bothSides(height.size(), -1);

        int maxx = height[0];
        for (int i = 1; i < height.size(); i++) {
           maxx = max(maxx, height[i]);
           if (maxx >= height[i]) bothSides[i] = maxx;
        }

        maxx = height[height.size()-1];
        for (int i = height.size()-1; i >= 0; i--) {
            maxx = max(maxx, height[i]);
            if (maxx >= height[i] && bothSides[i] != -1) bothSides[i] = min(maxx, bothSides[i]);
        }

        int sum = 0;
        for (int i = 1; i < height.size()-1; i++) {
            if (bothSides[i] > height[i]) {
                sum += bothSides[i] - height[i];
            }
        }
        return sum;
    }
};