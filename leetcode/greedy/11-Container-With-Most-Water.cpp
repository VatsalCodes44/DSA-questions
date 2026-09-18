#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0; int j = height.size()-1;
        int area = 0;
        while (i < j) {
            if (height[i] <= height[j]){
                area = max(area, height[i]*(j-i));
                i++;
            }
            else {
                area = max(area, height[j]*(j-i));
                j--;
            }
        }
        return area;
    }
};