#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0;
        int r = 0;
        int minSumWindow = INT_MAX;
        int sum = 0;
        int totalSum = 0;
        while (r < cardPoints.size()) {
            sum += cardPoints[r];
            totalSum += cardPoints[r];
            if (r-l+1 == cardPoints.size()-k) {
                minSumWindow = min(minSumWindow, sum);
                sum -= cardPoints[l];
                l++;
            }
            r++;
        }
        if (k == cardPoints.size()) return totalSum;
        return totalSum - minSumWindow;
    }
};
